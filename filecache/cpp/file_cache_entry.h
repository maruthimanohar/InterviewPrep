#ifndef FILE_CACHE_ENTRY_H
#define FILE_CACHE_ENTRY_H

#include <stdlib.h>

class FileCacheEntry
{
public: // c-tor & d-tor
	FileCacheEntry(const std::string& file_name, int file_size)
		:_file_name(file_name), _file_size(file_size), _ref_count(0),
		 _dirty(false), _delete(false)
	{
		_buffer = (char *)calloc(sizeof(char), file_size);
	}

	~FileCacheEntry()
	{
		free(_buffer);
	}

public: // Member functions
	void increment_ref_count() { _ref_count++; }

	void decrement_ref_count() { _ref_count--; }

    int get_ref_count() { return _ref_count; }
	void mark_dirty()
	{
		time(&_dirty_start_time);
		_dirty = true;
	}

	void mark_clean() { _dirty = false; }

	bool is_dirty() { return _dirty; }

	void mark_delete() { _delete = true; }

	bool is_delete() { return _delete; }

	char *get_writable_buffer() { return _buffer; }

	const char *get_readonly_buffer() { return _buffer; }

	time_t get_dirty_start_time() { return _dirty_start_time; }

private: // Data memebers
	std::string _file_name;
	int _file_size;
	int _ref_count;
	char *_buffer;
	bool _dirty;
	time_t _dirty_start_time;
	bool _delete;
};

#endif
