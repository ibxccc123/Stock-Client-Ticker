#ifndef CHAINEDHASHRMS_H_
#define CHAINEDHASHRMS_H_

#include "DList.h"
#include <vector>
using std::vector;

template <typename I>
class ChainedHash
{
public:
	class iterator
	{
		typename DList<I>::iterator list_iter;

		iterator(const typename DList<I>::iterator& l_iter)
			:list_iter(l_iter){}

		friend class ChainedHash<I>;

	public:
		iterator(const iterator& other)
			:list_iter(other.list_iter){}

		iterator& operator=(const iterator& rhs)
		{
			list_iter = rhs.list_iter;
			return *this;
		}

		I& operator*() const
		{
			return *list_iter;
		}

		iterator& operator++()
		{
			++list_iter;
			return *this;
		}

		iterator operator++(int)
		{
			iterator oldMe = *this;
			list_iter++;
			return oldMe;
		}

		bool operator==(const iterator& rhs) const
		{
			return list_iter == rhs.list_iter;
		}

		bool operator!=(const iterator& rhs) const
		{
			return list_iter != rhs.list_iter;
		}
	};

private:
	DList<I> list;
	vector<iterator> vec;
	size_t n, buckets;

public:
	explicit ChainedHash(size_t buckets = 10000)
		:list(DList<I>())
		,vec(vector<iterator>())
		,n(0), buckets(buckets)
	{
		for (size_t bucket = 0; bucket < buckets; bucket++)
		{
			iterator iter = iterator(list.insert(list.end(), I()));
			vec.push_back(iter);
		}
		vec.push_back(iterator(list.end()));
	}

	~ChainedHash(){}

	iterator begin() const
	{
		return iterator(list.begin());
	}

	iterator end() const
	{
		return iterator(list.end());
	}

	iterator find(const I& item) const
	{
		size_t h = hash(item) % buckets;
		for(iterator iter = vec[h]; iter != vec[h+1]; iter++){
			if(*iter == item)
				return iter;
		}
		return end();

	}

      size_t hash(const string& s) const{
      size_t h = 0;
      for(size_t i=0; i<s.length(); i++){
         h = (h * 31) + s.at(i);
      }
      return h;
   }

//REQ: I must have str()
   size_t hash(const I& item) const{
      return hash(item.str());
   }

        iterator insert(const I& item)
	{
		size_t h = hash(item) % buckets;
		for (iterator iter = vec[h]; iter != vec[h+1]; iter++)
			if (*iter == item)
				return iter;
		++n;
		return iterator(list.insert(vec[h+1].list_iter, item));
	}

	size_t size() const
	{
		return n;
	}

	bool empty() const
	{
		return size() == 0;
	}

	string str() const
	{
		return list.toString();
	}
};

#endif

