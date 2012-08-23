//
// Copyright (c) 2011 Nutanix Inc. All rights reserved.
//
// The problem is to implement a file cache in C++ that derives the interface
// given below in class FileCache. The typical usage is for a client to call
// 'PinFiles()' to pin a bunch of files in the cache and then either read or
// write to their in-memory contents in the cache. Writing to a cache entry
// makes that entry 'dirty'. Before a dirty entry can be evicted from the
// cache, it must be unpinned and has to be cleaned by writing the
// corresponding data to disk.
//
// All files are assumed to have size 10KB. If a file doesn't exist to begin
// with, it should be created and filled with zeros - the size should be 10KB.
//
// FileCache should be a thread-safe object that can be simultaneously
// accessed by multiple threads. If you are not comfortable with concurrent
// programming, then it may be single-threaded (see alternative in the
// PinFiles() comment). To implement the problem in its entirety may require
// use of third party libraries and headers. For the sake of convenience, it
// is permissible (although not preferred) to substitute external functions
// with stub implementations, but in doing so, please be clear what the
// intended behavior and side effects would be.
//
// Do not be overly concerned about portability. Pick your platform of choice
// (Nutanix develops on Linux) and be consistent. You may use C++11
// functionality.
//
// The problem is expected to take no longer than four hours (it is not
// necessary to work for that complete time). We'd rather see a stable and
// clean solution that implements a subset of the functionality than a
// complete but buggy one. There is no strict threshold on the time limit, so
// if you need a extra time to organize and improve the readability of your
// solution, please do so.
//
// If you have any questions, please email both brian@nutanix.com and
// bnc@nutanix.com. If no reply is received in a timely manner, please make a
// judgement call and state your assumptions in the code or response email.

#ifndef _NUTANIX_FILE_CACHE_H_
#define _NUTANIX_FILE_CACHE_H_

#include <string>
#include <vector>

class FileCache {
 public:
  // Constructor. 'max_cache_entries' is the maximum number of files that can
  // be cached at any time. If a background flusher thread is implemented, then
  // 'dirty_time_secs' is the duration after which an unpinned, dirty file will
  // be cleaned (flushed to disk) by a background thread.
  FileCache(int max_cache_entries, int dirty_time_secs) :
    max_cache_entries_(max_cache_entries),
    dirty_time_secs_(dirty_time_secs) {
  }

  // Destructor. Flushes all dirty buffers and stops the background thread (if
  // implemented).
  virtual ~FileCache() {}

  // Pins the given files in vector 'file_vec' in the cache. If any of these
  // files are not already cached, they are first read from the local
  // filesystem. If the cache is full, then some existing cache entries may be
  // evicted. If no entries can be evicted (e.g., if they are all pinned, or
  // dirty), then this method will block until a suitable number of cache
  // entries becomes available. It is fine if more than one thread pins the
  // same file, however the file should not become unpinned until both pins
  // have been removed from the file.
  //
  // Correct usage of PinFiles() is assumed to be the caller's responsibility,
  // and therefore deadlock avoidance doesn't need to be handled. The caller is
  // assumed to pin all the files it wants using one PinFiles() call and not
  // call multiple PinFiles() calls without unpinning those files in the
  // interim.
  //
  // If you are not comfortable with multi-threaded programming or
  // synchronization, this function may be modified to return a boolean if
  // the requested files cannot be pinned due to the cache being full. However,
  // note that entries in 'file_vec' may already be pinned and therefore even a
  // full cache may add additional pins to files.
  virtual void PinFiles(const std::vector<std::string>& file_vec) = 0;

  // Unpin one or more files that were previously pinned. It is ok to unpin
  // only a subset of the files that were previously pinned using PinFiles().
  // It is undefined behavior to unpin a file that wasn't pinned.
  virtual void UnpinFiles(const std::vector<std::string>& file_vec) = 0;

  // Provide read-only access to a pinned file's data in the cache.
  //
  // It is undefined behavior if the file is not pinned, or to access the
  // buffer when the file isn't pinned.
  virtual const char *FileData(const std::string& file_name) = 0;

  // Provide write access to a pinned file's data in the cache. This call marks
  // the file's data as 'dirty'. The caller may update the contents of the file
  // by writing to the memory pointed by the returned value.
  //
  // It is undefined behavior if the file is not pinned, or to access the
  // buffer when the file is not pinned.
  virtual char *MutableFileData(const std::string& file_name) = 0;

  // Mark a file for deletion from the local filesystem. It may or may not be
  // pinned. If it is pinned, then the deletion is delayed until after the file
  // is unpinned.
  virtual void DeleteFile(const std::string& file_name) = 0;

 protected:
  // Maximum number of files that can be cached at any time.
  const int max_cache_entries_;

  // A background disk flush should be scheduled if an unpinned file in the
  // cache is dirty and hasn't been written to in at least 'dirty_time_secs_'
  // (if implemented).
  const int dirty_time_secs_;

 private:
  // Disallow copy and assign. Do *not* implement!
  FileCache(const FileCache&);
  FileCache& operator=(const FileCache&);
};

#endif  // _NUTANIX_FILE_CACHE_H_
