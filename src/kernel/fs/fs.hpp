#pragma once
#include "File.hpp"

#include "../types.hpp"
#include "../algo/String.hpp"

namespace kernel::fs {
using algorithms::String;

class FS {
public:
    FS() = default;
    ~FS() = default;

    virtual uint32_t read(const File& file, uint32_t offset, uint32_t size, void* buffer) { return 0; }
    virtual uint32_t write(const File& file, uint32_t offset, uint32_t size, void* buffer) { return 0; }
    virtual void open(File& file, uint32_t offset, uint32_t size, uint8_t* buffer) { }
    virtual void close(File& file, uint32_t offset, uint32_t size, uint8_t* buffer) { }
    virtual File finddir(const File& directory, const String& filename) { }
    virtual File& create(const File& directory, File& file) { }
};

}