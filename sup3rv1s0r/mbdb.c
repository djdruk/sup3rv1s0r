//
//  mbdb.c
//  sup3rv1s0r
//
//  Created by Samantha Demi on 4/29/14.
//  Copyright (c) 2014 Samantha Demi. All rights reserved.
//

#ifndef sup3rv1s0r_mbdb_c
#define sup3rv1s0r_mbdb_c

#include "mbdb.h"
#include "Core.h"
#include <time.h>

ATR_UNUSED static struct mbdb_manifest nuke_backup_header[] = { { {0x6d, 0x62, 0x64, 0x62}, 0x5 } };

#define kDefaultUser 501

#define kRecordCount 4

ATR_UNUSED static struct mbdb_record nuke_backup_info[kRecordCount] = {
	{
		{{10, "HomeDomain"}},
		{{0, NULL}},
		{{65535, NULL}},
		{{65535, NULL}},
		{{65535, NULL}},
		{(S_IFDIR) | (S_IRWXU) | (S_IXGRP) | (S_IXOTH), 0, 42, kDefaultUser, kDefaultUser, 0, 0, 0, 0, 0},
		0, 0
	},
	{
		{{10, "HomeDomain"}},
		{{7, "Library"}},
		{{65535, NULL}},
		{{65535, NULL}},
		{{65535, NULL}},
		{(S_IFDIR) | (S_IRWXU) | (S_IXGRP) | (S_IXOTH), 0, 44, kDefaultUser, kDefaultUser, 0, 0, 0, 0, 0},
		0, 0
	},
	{
		{{10, "HomeDomain"}},
		{{29, "Library/ConfigurationProfiles"}},
		{{65535, NULL}},
		{{65535, NULL}},
		{{65535, NULL}},
		{(S_IFDIR) | (S_IRWXU) | (S_IRGRP | S_IXGRP) | (S_IROTH | S_IXOTH), 0, 83, kDefaultUser, kDefaultUser, 0, 0, 0, 0, 4},
		0, 0
	},
	{
		{{10, "HomeDomain"}},
		{{61, "Library/ConfigurationProfiles/CloudConfigurationDetails.plist"}},
		{{65535, NULL}}, // the hash here VVV will always be the same because we are hashing the static data at the top of the nuke.c file (udid_plist[])
		{{20, (char *)((int8_t [20]){0xB5, 0x1C, 0xAB, 0x52, 0x37, 0xB9, 0xE7, 0x7F, 0x92, 0xCB, 0x25, 0x8B, 0xC7, 0x18, 0x66, 0xFD, 0xAF, 0x82, 0xF6, 0xCF})}},
		{{65535, NULL}},
		{(S_IFREG) | (S_IRUSR | S_IWUSR) | (S_IRGRP) | (S_IROTH), 0, 2173, kDefaultUser, kDefaultUser, 0, 0, 0, 182, 4},
		0, 0
	}
};

struct mbdb_file_name * FindFileForFromManifestRecord(struct mbdb_record * record) {
	struct mbdb_file_name * file = calloc(1, sizeof(struct mbdb_file_name));
	if (record->domain.name.length && record->path.name.length && record->data_hash.name.length == HASH_LENGTH) {
		CFStringRef file_name_format = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%s-%s"),record->domain.name.string, record->path.name.string);
		CFDataRef file_name_hash_data = CFStringCreateExternalRepresentation(NULL, file_name_format, kCFStringEncodingUTF8, 0);
		unsigned char * file_name_hash = DataToSHA1(file_name_hash_data);
		memcpy(file->name, file_name_hash, sizeof(char[HASH_LENGTH]));
		memcpy(file->hash, record->data_hash.name.string, sizeof(char[HASH_LENGTH]));
		CFSafeRelease(file_name_format);
		CFSafeRelease(file_name_hash_data);
		free(file_name_hash);
		file->has_file = true;
	}
	return file;
}

void AppendManifestRecordEntry(CFMutableDataRef * data, struct mbdb_record_entry * entry) {
	uint16_t be_name_length = be16toh(entry->name.length);
	CFDataAppendBytes(*data, (const UInt8 *)&be_name_length, sizeof(uint16_t));
	if (entry->name.length > 0 && entry->name.length < 65535) {
		CFDataAppendBytes(*data, (const UInt8 *)entry->name.string, entry->name.length);
	}
}

void AppendManifestRecordInfo(CFMutableDataRef * data, struct mbdb_record_info * info) {
	struct mbdb_record_info * flipped = calloc(1, sizeof(struct mbdb_record_info));
	flipped->mode = be16toh(info->mode);
	flipped->unknown0 = be32toh(info->unknown0);
	flipped->unknown1 = be32toh(info->unknown1);
	flipped->user_id = be32toh(info->user_id);
	flipped->group_id = be32toh(info->group_id);
	flipped->atime = be32toh(info->atime);
	flipped->mtime = be32toh(info->mtime);
	flipped->ctime = be32toh(info->ctime);
	flipped->file_length = be64toh(info->file_length);
	flipped->flag = info->flag;
	CFDataAppendBytes(*data, (const UInt8 *)flipped, sizeof(struct mbdb_record_info));
	free(flipped);
}

void AppendManifestRecord(CFMutableDataRef * data, struct mbdb_record * record) {
	AppendManifestRecordEntry(data, &(record->domain));
	
	AppendManifestRecordEntry(data, &(record->path));
	
	AppendManifestRecordEntry(data, &(record->target));
	
	AppendManifestRecordEntry(data, &(record->data_hash));
	
	AppendManifestRecordEntry(data, &(record->other));
	
	AppendManifestRecordInfo(data, &(record->info));
}

CFDataRef PrepareManifestMBDB() {
	CFMutableDataRef data = CFDataCreateMutable(kCFAllocatorDefault, 0);
	CFDataAppendBytes(data, (const UInt8 *)nuke_backup_header, sizeof(struct mbdb_manifest));

	struct mbdb_record * nuke = nuke_backup_info;
	for (uint8_t index = 0; index < kRecordCount; index++) {
		uint32_t time_val = (uint32_t)time(0);
		nuke[index].info.atime = time_val;
		nuke[index].info.mtime = time_val;
		nuke[index].info.ctime = time_val;
		
		AppendManifestRecord(&data, &(nuke[index]));
		
		CFDataAppendBytes(data, (const UInt8 *)&(nuke[index].property_count), sizeof(uint8_t));
	}
	
	return data;
}

uint32_t ParseMBDBString(struct mbdb_string * string, char * data) {
	uint32_t offset = sizeof(uint16_t);
	uint16_t length = 0;
	memcpy(&length, &(data[0]), sizeof(uint16_t));
	length = be16toh(length);
	if (length > 0 && length < 65535) {
		string->length = length;
		string->string = calloc(length+1, sizeof(char));
		memcpy(string->string, &(data[offset]), sizeof(char[length]));
		offset += length;
	}
	else {
		string->length = 0;
		string->string = NULL;
	}
	return offset;
}

uint32_t ParseMBDBRecordEntry(struct mbdb_record_entry * entry, char * data) {
	return ParseMBDBString(&(entry->name), data);
}

uint32_t ParseMBDBRecordInfo(struct mbdb_record_info * info, char * data) {
	uint32_t offset = sizeof(struct mbdb_record_info);
	memcpy(info, data, offset);
	info->mode = be16toh(info->mode);
	info->unknown0 = be32toh(info->unknown0);
	info->unknown1 = be32toh(info->unknown1);
	info->user_id = be32toh(info->user_id);
	info->group_id = be32toh(info->group_id);
	info->atime = be32toh(info->atime);
	info->mtime = be32toh(info->mtime);
	info->ctime = be32toh(info->ctime);
	info->file_length = be64toh(info->file_length);
	return offset;
}

struct mbdb_file * ParseMBDBData(CFDataRef file) {
	struct mbdb_file * mbdb = calloc(1, sizeof(struct mbdb_file));
	if (mbdb) {
		char * data = (char *)CFDataGetBytePtr(file);
		
		bool can_parse = false;
		if (strncmp(data, kMBDB_MAGIC, sizeof(char[4])) == 0) {
			can_parse = true;
		}
		
		if (can_parse) {
			mbdb->manifest = calloc(1, sizeof(struct mbdb_manifest));
			memcpy(mbdb->manifest, data, sizeof(struct mbdb_manifest));
			CFIndex length = CFDataGetLength(file);
			
			mbdb->record = calloc(1, sizeof(struct mbdb_record));
			
			uint32_t offset = sizeof(struct mbdb_manifest);;
			while (offset < length) {
				mbdb->record = realloc(mbdb->record, sizeof(struct mbdb_record)*(mbdb->record_count+1));
				
				offset += ParseMBDBRecordEntry(&(mbdb->record[mbdb->record_count].domain), &(data[offset]));
				offset += ParseMBDBRecordEntry(&(mbdb->record[mbdb->record_count].path), &(data[offset]));
				offset += ParseMBDBRecordEntry(&(mbdb->record[mbdb->record_count].target), &(data[offset]));
				offset += ParseMBDBRecordEntry(&(mbdb->record[mbdb->record_count].data_hash), &(data[offset]));
				offset += ParseMBDBRecordEntry(&(mbdb->record[mbdb->record_count].other), &(data[offset]));
				offset += ParseMBDBRecordInfo(&(mbdb->record[mbdb->record_count].info), &(data[offset]));
				
				memcpy(&(mbdb->record[mbdb->record_count].property_count), &(data[offset]), sizeof(uint8_t));
				offset += sizeof(uint8_t);
				if (mbdb->record[mbdb->record_count].property_count > 0) {
					mbdb->record[mbdb->record_count].property = calloc(mbdb->record[mbdb->record_count].property_count, sizeof(struct mbdb_record_property));
					for (uint8_t index = 0; index < mbdb->record[mbdb->record_count].property_count; index++) {
						offset += ParseMBDBString(&(mbdb->record[mbdb->record_count].property[index].name), &(data[offset]));
						offset += ParseMBDBString(&(mbdb->record[mbdb->record_count].property[index].value), &(data[offset]));
					}
				}
				else {
					mbdb->record[mbdb->record_count].property = NULL;
				}
				mbdb->record_count++;
			}
			
		}
	}
	return mbdb;
}

struct mbdb_file * ParseMBDBFile(char * path) {
	CFDataRef file = CFDataCreateFromFilePath(path);
	struct mbdb_file * mbdb = ParseMBDBData(file);
	CFSafeRelease(file);
	return mbdb;
}

void MBDBStringRelease(struct mbdb_string string) {
	if (string.length) {
		free(string.string);
	}
}

void MBDBRecordRelease(struct mbdb_record * record) {
	if (record) {
		MBDBStringRelease(record->domain.name);
		MBDBStringRelease(record->path.name);
		MBDBStringRelease(record->target.name);
		MBDBStringRelease(record->data_hash.name);
		MBDBStringRelease(record->other.name);
		if (record->property_count) {
			for (uint8_t index = 0; index < record->property_count; index++) {
				MBDBStringRelease(record->property[index].name);
				MBDBStringRelease(record->property[index].value);
			}
			free(record->property);
		}
	}
}

void MBDBFileRelease(struct mbdb_file * file) {
	if (file) {
		if (file->manifest) {
			free(file->manifest);
		}
		if (file->record_count) {
			for (uint32_t index = 0; index < file->record_count; index++) {
				MBDBRecordRelease(&(file->record[index]));
			}
			free(file->record);
		}
		else {
			Safe(free,file->record);
		}
		free(file);
	}
}

#endif