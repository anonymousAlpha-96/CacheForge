
#include "cacheforge/CacheEngine.h"

void CacheEngine::set(const std::string& key, const std::string& value)
{
    cache_[key] = value;
}

std::optional<std::string> CacheEngine::get(const std::string& key)const
{
    auto it = cache_.find(key);
    if(it != cache_.end())
    {
        return it->second;
    }
    return std::nullopt;
}
bool CacheEngine::exists(const std::string& key) const
{
    return cache_.find(key) != cache_.end();
}

bool CacheEngine::remove(const std::string& key)
{
    return cache_.erase(key) > 0;
}


