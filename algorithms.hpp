#ifndef PR_3_ALGORITHMS_HPP
#define PR_3_ALGORITHMS_HPP

namespace algs {
    template<class InputIt, class UnaryPredicate>
    bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
        for (; first != last; ++first) {
            if (!p(*first)) {
                return false;
            }
        }
        return true;
    }

    template<class InputIt, class UnaryPredicate>
    bool any_of(InputIt first, InputIt last, UnaryPredicate p) {
        for (; first != last; ++first) {
            if (p(*first)) {
                return true;
            }
        }
        return false;
    }

    template<class InputIt, class UnaryPredicate>
    bool none_of(InputIt first, InputIt last, UnaryPredicate p) {
        return !any_of(first, last, p);
    }

    template<class InputIt, class UnaryPredicate>
    bool one_of(InputIt first, InputIt last, UnaryPredicate p) {
        int counter = 0;
        for (; first != last; ++first) {
            if (p(*first)) {
                ++counter;
                if (counter > 1)
                    return false;
            }
        }
        if (counter == 1) return true;
        return false;
    }


    template<class ForwardIt, class Compare>
    bool is_sorted(ForwardIt first, ForwardIt last, Compare comp) {
        if (first != last) {
            ForwardIt next = first;
            while (++next != last) {
                if (comp(*next, *first)) {
                    return next == last;
                }
                first = next;
            }
        }
        return true;
    }

    template<class InputIterator, class UnaryPredicate>
    bool is_partitioned(InputIterator first, InputIterator last, UnaryPredicate pred) {
        while (first != last && pred(*first)) {
            ++first;
        }
        while (first != last) {
            if (pred(*first))
                return false;
            ++first;
        }
        return true;
    }

    template<class InputIt, class T>
    InputIt find_not(InputIt first, InputIt last, const T &value) {
        for (; first != last; ++first) {
            if (*first != value) {
                return first;
            }
        }
        return last;
    }

    template<class InputIt, class T>
    InputIt find_backward(InputIt first, InputIt last, const T &value) {
        for (; last != first; --last) {
            if (*last == value) {
                return last;
            }
        }
        return first;
    }

    template<class InputIt1, class InputIt2, class BinaryPredicate>
    bool is_palindrome(InputIt1 first1, InputIt1 last1,
                       InputIt2 first2, BinaryPredicate p) {
        for (; first1 != last1; ++first1, ++first2) {
            if (!p(*first1, *first2)) {
                return false;
            }
        }
        return true;
    }
}

#endif //PR_3_ALGORITHMS_HPP
