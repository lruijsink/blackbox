#pragma once
#include <map>
#include <string>

namespace blackbox
{
    template<class ElementT>
    class ff_environment_dictionary
    {
    public:
        void add(std::string key,
                 ElementT el)
        {
            m_map.insert(std::make_pair(key, el));
        }

        ElementT operator[](std::string key) const
        {
            return m_map.at(key);
        }
        
    private:
        std::map<std::string, ElementT> m_map;
    };
}
