#ifndef FILE_CACHE_IMPL_H
#define FILE_CACHE_IMPL_H

#include "file_cache.h"
#include "file_cache_entry.h"

#include <map>
#include <pthread.h>
class FileCacheImpl : public FileCache
{
public: // c-tor & d-tor
	FileCacheImpl(int max_cache_entries, int dirty_time_secs);
	~FileCacheImpl();

public: // Methods
	void PinFiles(const std::vector<std::string>& file_vec);
	void UnpinFiles(const std::vector<std::string>& file_vec);
	const char *FileData(const std::string& file_name);
	char *MutableFileData(const std::string& file_name);
	void DeleteFile(const std::string& file_name);

private:
	  // Disallow copy and assign. Do *not* implement!
	FileCacheImpl(const FileCacheImpl&);
	FileCacheImpl& operator=(const FileCacheImpl&);

	static void *bg_thread_func(void *obj)
	{
		FileCacheImpl *file_cache_impl = (FileCacheImpl *)obj;
		file_cache_impl->bg_thread();
		return NULL;
	}
	void *bg_thread();
    void pin_file(const std::string& file_name);
    FileCacheEntry *get_cache_entry(const std::string& file_name);
    void unpin_file(const std::string& file_name);
    int evict_an_entry();

private: // Data Members
    pthread_t bg_t;
	pthread_mutex_t _lock;
	pthread_cond_t _cond;
	int _num_cache_entries;
	std::map<std::string, FileCacheEntry *> _cache;
    bool _stopped;
};

#endif
