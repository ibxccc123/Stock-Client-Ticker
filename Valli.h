#ifndef  VALLI_H_
#define VALLI_H_

#include "DList.h"
#include <vector>
using std::vector;

template <typename I>
class valli
{
public:
    class iterator
    {
        typename DList<I>::iterator list_iter;

        iterator(const typename DList<I>::iterator& l_iter)
            :list_iter(l_iter){}

        friend class valli<I>;

    public:
        iterator(){}

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
    size_t n, r;

public:
    explicit valli(size_t ratio = 500)
        :list(DList<I>())
        ,vec(vector<iterator>())
        ,n(0), r(ratio){}

    ~valli(){}

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
        iterator left = begin();
        iterator right = end();
        for (typename vector<iterator>::iterator v_iter = vec.begin(); v_iter != vec.end(); v_iter++)
            if (item < **v_iter)
            {
                right = *v_iter;
                break;
            }
            else
                left = *v_iter;
        for (iterator iter = left; iter != right; iter++)
        {
            if (*iter == item)
                return iter;
            if (*iter > item)
                return end();
        }
        return end();
    }

    iterator insert(const I& item)
    {
        iterator left = begin();
        iterator right = end();
        for (typename vector<iterator>::iterator v_iter = vec.begin(); v_iter != vec.end(); v_iter++)
            if (item < **v_iter)
            {
                right = *v_iter;
                break;
            }
            else
                left = *v_iter;
        iterator iter = left;
        for (; iter != right; iter++)
            if (*iter >= item)
                break;
        iterator result(list.insert(iter.list_iter, item));
        if (++n > 2 * r * vec.size())
            refresh();
        return result;
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

    void refresh(size_t newRatio)
    {
        r = newRatio;
        vec.clear();
        size_t count = r;
        for (iterator iter = begin(); iter != end(); iter++, count++)
            if (count == r)
            {
                count = 0;
                vec.insert(vec.end(), iter);
            }
    }

    void refresh()
    {
        refresh(r);
    }
};

#endif
