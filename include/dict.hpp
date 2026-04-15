#pragma once
#include <algorithm>
#include <vector>
#include <tuple>
#include <iterator>
#include <optional>

/**
 * @brief Container used to store assoicate keys with values.
 * values can later be retrived using the corresponding key.
 * 
 * @tparam K type of the keys stored in the dictionary.
 * @tparam V type of the values assoicated with each key.
 */
template <class K, class V>
class Dict
{
private:
    std::vector<K> keyStorage; // Stores all keys
    std::vector<V> valueStorage;  // Stores all values

public:
    /**
     * @brief Associates the key with the specified value.
     * If the key is already in the dictionary its value is overwritten.
     * 
     * @param key key associated with the provided key.
     * @param val value assoicated with the provided key.
     */
    void set(K key, V val)
    {
        // Search for key in key storage
        for(size_t i = 0; i < keyStorage.size(); i++){
            if(keyStorage[i] == key){
                // If key is found -> overwrite existing value
                valueStorage[i] = val;
                return;
            }
        }

        // Key not found -> insert new key-value pair
        keyStorage.push_back(key);
        valueStorage.push_back(val);
    }

    /**
     * @brief Determines if the key is defined in the dictionary.
     * 
     * @param key key for which to look for.
     * @return true if the key is defined in the dictionary.
     * @return false otherwise.
     */
    bool has(K key) const
    {
        // Go through keys: 
        // true if found; false if not
        for(const auto& k : keyStorage){
            if(k == key){
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Returns the number of items in the dictionary.
     * 
     * @return the number of items in the dictionary.
     */
    size_t len()
    {
        // Return number of keys
        return keyStorage.size();
    }

    /**
     * @brief Get the value associated with the specified key.
     * If no value is found std::nullopt is returned.
     * 
     * @param key key for which to locate value.
     * @return value associated with key.
     */
    std::optional<V> get(K key) const
    {
        // Search for key
        for(size_t i = 0; i < keyStorage.size(); i++){
            if(keyStorage[i] == key){
                return valueStorage[i]; // Return associated value from storage
            }
        }

        // Key not found -> no value to return
        return std::nullopt;
    }

    /**
     * @brief Delete the specified key and its associated value
     * from the dictionary.
     * If the key is not present in the dictionary, nothing happens.
     * 
     * @param key A key currently present in the dictionary
     * which will be deleted.
     */
    void del(K key)
    {
        // Search for key
        for(size_t i = 0; i < keyStorage.size(); i++){
            if(keyStorage[i] == key){
                // Delete key and corresponding value
                keyStorage.erase(keyStorage.begin() + i);
                valueStorage.erase(valueStorage.begin() + i);
                return;
            }
        }
        // If key not found -> do nothing
    }

    /**
     * @brief List all keys of the dictionary.
     * 
     * @return vector of keys.
     */
    std::vector<K> keys()
    {
        // Return all keys from storage
        return keyStorage;
    }

    /**
     * @brief List all values of the dictionary.
     * 
     * @return vector of values.
     */
    std::vector<V> values()
    {
        // Return all values from storage
        return valueStorage;
    }
};