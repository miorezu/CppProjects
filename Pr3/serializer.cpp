#include "serializer.h"

std::string ToXML(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent)
{
    std::string result = indent + "<" + tagName + ">\n";
    for (const auto& [key, value] : data)
    {
        result += indent + "  <" + key + ">" + value + "</" + key + ">\n";
    }
    result += indent + "</" + tagName + ">\n";
    return result;
}

std::string ToXML(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent)
{
    std::string result = indent + "<" + tagName + ">\n";
    for (const auto& item : data)
    {
        result += indent + "  <item>" + item + "</item>\n";
    }
    result += indent + "</" + tagName + ">\n";
    return result;
}

std::string ToXML(const std::string& tagName, const std::string& data, const std::string& indent)
{
    return indent + "<" + tagName + ">" + data + "</" + tagName + ">\n";
}

std::string ToJSON(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent)
{
    std::string result = indent + "\"" + tagName + "\": {\n";
    for (auto it = data.begin(); it != data.end(); ++it)
    {
        result += indent + "  \"" + it->first + "\": \"" + it->second + "\"";
        if (std::next(it) != data.end()) result += ",";
        result += "\n";
    }
    result += indent + "}";
    return result;
}

std::string ToJSON(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent)
{
    std::string result = indent + "\"" + tagName + "\": [\n";
    for (size_t i = 0; i < data.size(); ++i)
    {
        result += indent + "  \"" + data[i] + "\"";
        if (i != data.size() - 1) result += ",";
        result += "\n";
    }
    result += indent + "]";
    return result;
}

std::string ToJSON(const std::string& tagName, const std::string& data, const std::string& indent)
{
    return indent + "\"" + tagName + "\": \"" + data + "\"";
}

std::string ToYAML(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent)
{
    std::string result = indent + tagName + ":\n";
    for (const auto& [key, value] : data)
    {
        result += indent + "  " + key + ": " + value + "\n";
    }
    return result;
}

std::string ToYAML(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent)
{
    std::string result = indent + tagName + ":\n";
    for (const auto& item : data)
    {
        result += indent + "  - " + item + "\n";
    }
    return result;
}

std::string ToYAML(const std::string& tagName, const std::string& data, const std::string& indent)
{
    return indent + tagName + ": " + data + "\n";
}
