#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
    *this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
    (void)src;
    return *this;
}

bool PmergeMe::parse_input(int argc, char **argv)
{
    if (argc == 2)
    {
        std::stringstream ss(argv[1]);
        int n;
        while (ss >> n)
        {
            _vec.push_back(n);
            _deque.push_back(n);
        }
    }
    else{
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j]; j++)
            {
                //std::cout << argv[i][j] << std::endl;
                if (argv[i][j] < '0' || argv[i][j] > '9')
                {
                    std::cerr << "Bad input (only positive numbers!)"<< std::endl;
                    return false;
                }
            }
            int num = std::atoi(argv[i]);
            _vec.push_back(num);
            _deque.push_back(num);
        }
    }
    return true;
}

template <typename T>
void PmergeMe::display_container(T &container)
{
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void print_pairs(const Container &pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")";
    }
    std::cout << std::endl;
}

//-----------------------DEQUE-------------------------------
// 1. делим на пары
std::deque<std::pair<int, int> > splitIntoPairs_deque(std::deque<int> &deq)
{
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < deq.size(); i += 2)
    {
        if (i + 1 < deq.size())
            pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
    }
    return pairs;
}

// 2. сортируем элементы внутри каждой пары
void sortPairs_deque(std::deque<std::pair<int, int> >& pairs) {
        for (size_t i = 0; i < pairs.size(); ++i) {
            if (pairs[i].first < pairs[i].second) {
                std::swap(pairs[i].first, pairs[i].second); // Меняем местами, если первый элемент меньше второго
            }
        }
    }

// 3. Рекурсивная сортировка и слияние пар
void merge_deque(std::deque<std::pair<int, int> >& pairs, int begin, int mid, int end) {
        std::deque<std::pair<int, int> > leftArray(pairs.begin() + begin, pairs.begin() + mid);
        std::deque<std::pair<int, int> > rightArray(pairs.begin() + mid, pairs.begin() + end);
        
        size_t leftIndex = 0, rightIndex = 0, mergedIndex = begin;
        // Слияние
        while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
            if (leftArray[leftIndex].first <= rightArray[rightIndex].first) {
                pairs[mergedIndex++] = leftArray[leftIndex++];
            } else {
                pairs[mergedIndex++] = rightArray[rightIndex++];
            }
        }
        // Копируем оставшиеся элементы
        while (leftIndex < leftArray.size()) {
            pairs[mergedIndex++] = leftArray[leftIndex++];
        }
        while (rightIndex < rightArray.size()) {
            pairs[mergedIndex++] = rightArray[rightIndex++];
        }
    }
        
void mergeSort_deque(std::deque<std::pair<int, int> >& pairs, int begin, int end) {
        if (end - begin < 2) {
            return; // Если массив имеет менее двух элементов, он уже отсортирован
        }
        int mid = begin + (end - begin) / 2;
        mergeSort_deque(pairs, begin, mid); // Сортируем левую половину
        mergeSort_deque(pairs, mid, end);    // Сортируем правую половину
        merge_deque(pairs, begin, mid, end);  // Сливаем отсортированные половины
    }

//4. Создание последовательности S из первых элементов пар и последовательности L из вторых элементов пар.
void PmergeMe::create_S_L_deque(std::deque<std::pair<int, int> >& pairs){
    for (size_t i = 0; i < pairs.size(); ++i) {
        _S_deque.push_back(pairs[i].first);
        _L_deque.push_back(pairs[i].second);
    }
    _S_deque.insert(_S_deque.begin(), _L_deque[0]);//Вставляем первый элемент из L в начало S.
}

// 5.бинарный поиск, используя числа Якобсталя
long unsigned int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// находим последовательность чисел Якобсталя в зависимости от размера вектора L
// J(n)=J(n−1)+J(n−2)*2 -> 0 1 1 3 5 11 21 43 85 171 341 683...
void find_jacobsthal_sequence_deque(std::deque<int> &L_deque, std::deque<int> &jacobsthal_sequence_deque) {
    int index = 3;
    while (jacobsthal(index) < L_deque.size() - 1) {
        jacobsthal_sequence_deque.push_back(jacobsthal(index));
        index++;
    }
}

//находим последовательность позиций для вставки в S
// L = {2 1 3 8 4 11 56} -> Jacob Sequence: 3 5 -> Positions: 3 2 5 4 6 7
//Jacob Sequence: 3 5 11 -> Positions: 3 2 5 4 11 10 9 8 7 6 + остаток индексов L по порядку
void find_positions_deque(std::deque<int> &L_deque, std::deque<int> &positions_deque) {
    std::deque<int> jacobsthal_sequence_deque;
    find_jacobsthal_sequence_deque(L_deque, jacobsthal_sequence_deque);
    size_t lastPos = 1;
    size_t val = 1;
    for (size_t i = 0; i < jacobsthal_sequence_deque.size(); ++i) {
        val = jacobsthal_sequence_deque[i];
        positions_deque.push_back(val);
        size_t pos = val - 1;
        while (pos > lastPos) {
            positions_deque.push_back(pos);
            pos--;
        }
        lastPos = val;
    }
    while (val++ < L_deque.size()) {
        positions_deque.push_back(val);
    }
}

//бинарный поиск
int binary_search_deque(std::deque<int> &S, int target, int begin, int end) {
    int mid;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        if (target == S[mid]) return mid;
        if (target > S[mid]) begin = mid + 1;
        else end = mid - 1;
    }
    if (target > S[mid]) return mid + 1;
    else return mid;
}

// Вставляем элементы из L в S с помощью бинарного поиска
void insert_elements_deque(std::deque<int> &S_deque, std::deque<int> &L_deque, std::deque<int> &positions_deque) {
    size_t endPos;
    size_t addedCount;
    size_t pos;
    addedCount = 0;
    for (size_t i = 0; i < positions_deque.size(); ++i) {
        int target = L_deque[positions_deque[i] - 1];
        endPos = positions_deque[i] + addedCount;
        pos = binary_search_deque(S_deque, target, 0, endPos);
        S_deque.insert(S_deque.begin() + pos, target);
        addedCount++;
    }
}

void add_struggler(std::deque<int> &S_deque, std::deque<int> &deque) {
    int target = deque[deque.size() - 1];
    int pos = binary_search_deque(S_deque, target, 0, S_deque.size());
    S_deque.insert(S_deque.begin() + pos, target);
}

void PmergeMe::sort_deque(std::deque<int> &deq) {
    if (deq.size() == 1) {
        _S_deque.push_back(deq[0]);
        return;
    }
    std::deque<std::pair<int, int> > pairs = splitIntoPairs_deque(deq);// Получаем пары
    sortPairs_deque(pairs); // Сортируем элементы внутри каждой пары
    mergeSort_deque(pairs, 0, pairs.size()); // Сортируем пары слиянием print_pairs(pairs);
    create_S_L_deque(pairs); // Создаем последовательности S и L
    std::deque<int> positions_deque;
    find_positions_deque(_L_deque, positions_deque);
    insert_elements_deque(_S_deque, _L_deque, positions_deque); // Вставляем элементы из L в S с помощью бинарного поиска
    add_struggler(_S_deque, deq); //add last element if size is odd
}

//-----------------------VECTOR-------------------------------
// 1. делим на пары
std::vector<std::pair<int, int> > splitIntoPairs(std::vector<int> &vec)
{
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (i + 1 < vec.size())
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
    return pairs;
}

// 2. сортируем элементы внутри каждой пары
void sortPairs(std::vector<std::pair<int, int> >& pairs) {
        for (size_t i = 0; i < pairs.size(); ++i) {
            if (pairs[i].first < pairs[i].second) {
                std::swap(pairs[i].first, pairs[i].second); // Меняем местами, если первый элемент меньше второго
            }
        }
    }

// 3. Рекурсивная сортировка и слияние пар
void merge(std::vector<std::pair<int, int> >& pairs, int begin, int mid, int end) {
        std::vector<std::pair<int, int> > leftArray(pairs.begin() + begin, pairs.begin() + mid);
        std::vector<std::pair<int, int> > rightArray(pairs.begin() + mid, pairs.begin() + end);
        
        size_t leftIndex = 0, rightIndex = 0, mergedIndex = begin;
        // Слияние
        while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
            if (leftArray[leftIndex].first <= rightArray[rightIndex].first) {
                pairs[mergedIndex++] = leftArray[leftIndex++];
            } else {
                pairs[mergedIndex++] = rightArray[rightIndex++];
            }
        }
        // Копируем оставшиеся элементы
        while (leftIndex < leftArray.size()) {
            pairs[mergedIndex++] = leftArray[leftIndex++];
        }
        while (rightIndex < rightArray.size()) {
            pairs[mergedIndex++] = rightArray[rightIndex++];
        }
    }

void mergeSort(std::vector<std::pair<int, int> >& pairs, int begin, int end) {
        if (end - begin < 2) {
            return; // Если массив имеет менее двух элементов, он уже отсортирован
        }
        int mid = begin + (end - begin) / 2;
        mergeSort(pairs, begin, mid); // Сортируем левую половину
        mergeSort(pairs, mid, end);    // Сортируем правую половину
        merge(pairs, begin, mid, end);  // Сливаем отсортированные половины
    }

//4. Создание последовательности S из первых элементов пар и последовательности L из вторых элементов пар.
void PmergeMe::create_S_L(std::vector<std::pair<int, int> >& pairs){
    //std::vector<int> S;
    //std::vector<int> L;
    for (size_t i = 0; i < pairs.size(); ++i) {
        _S.push_back(pairs[i].first);
        _L.push_back(pairs[i].second);
    }
    _S.insert(_S.begin(), _L[0]);//Вставляем первый элемент из L в начало S.
    //display_container(_S);
    //display_container(_L);
}

// 5.бинарный поиск, используя числа Якобсталя
/*long unsigned int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}*/

// находим последовательность чисел Якобсталя в зависимости от размера вектора L
// J(n)=J(n−1)+J(n−2)*2 -> 0 1 1 3 5 11 21 43 85 171 341 683...
void find_jacobsthal_sequence(std::vector<int> &L, std::vector<int> &jacobsthal_sequence) {
    int index = 3;
    while (jacobsthal(index) < L.size() - 1) {
        jacobsthal_sequence.push_back(jacobsthal(index));
        index++;
    }
}

//находим последовательность позиций для вставки в S
// L = {2 1 3 8 4 11 56} -> Jacob Sequence: 3 5 -> Positions: 3 2 5 4 6 7
//Jacob Sequence: 3 5 11 -> Positions: 3 2 5 4 11 10 9 8 7 6 + остаток индексов L по порядку
void find_positions(std::vector<int> &L, std::vector<int> &positions) {
    std::vector<int> jacobsthal_sequence;
    find_jacobsthal_sequence(L, jacobsthal_sequence);
    size_t lastPos = 1;
    size_t val = 1;
    for (size_t i = 0; i < jacobsthal_sequence.size(); ++i) {
        val = jacobsthal_sequence[i];
        positions.push_back(val);
        size_t pos = val - 1;
        while (pos > lastPos) {
            positions.push_back(pos);
            pos--;
        }
        lastPos = val;
    }
    while (val++ < L.size()) {
        positions.push_back(val);
    }
}

//бинарный поиск
int binary_search(std::vector<int> &S, int target, int begin, int end) {
    int mid;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        if (target == S[mid]) return mid;
        if (target > S[mid]) begin = mid + 1;
        else end = mid - 1;
    }
    if (target > S[mid]) return mid + 1;
    else return mid;
}

// Вставляем элементы из L в S с помощью бинарного поиска
void insert_elements(std::vector<int> &S, std::vector<int> &L, std::vector<int> &positions) {
    size_t endPos;
    size_t addedCount;
    size_t pos;
    addedCount = 0;
    for (size_t i = 0; i < positions.size(); ++i) {
        int target = L[positions[i] - 1];
        endPos = positions[i] + addedCount;
        //pos = std::lower_bound(S.begin(), S.begin() + endPos, target) - S.begin();
        pos = binary_search(S, target, 0, endPos);
        S.insert(S.begin() + pos, target);
        addedCount++;
    }
}

void add_struggler(std::vector<int> &S, std::vector<int> &vec) {
    int target = vec[vec.size() - 1];
    int pos = binary_search(S, target, 0, S.size());
    S.insert(S.begin() + pos, target);
}

void PmergeMe::sort_vector(std::vector<int> &vec)
{
    if (vec.size() == 1)
    {
        _S.push_back(vec[0]);
        return;
    }
    std::vector<std::pair<int, int> > pairs = splitIntoPairs(vec);// Получаем пары
    sortPairs(pairs); // Сортируем элементы внутри каждой пары
    mergeSort(pairs, 0, pairs.size()); // Сортируем пары слиянием print_pairs(pairs);
    create_S_L(pairs); // Создаем последовательности S и L
    std::vector<int> positions;
    find_positions(_L, positions);
    insert_elements(_S, _L, positions);// Вставляем элементы из L в S с помощью бинарного поиска
    if (vec.size() % 2 != 0) //add last element if size is odd
        add_struggler(_S, vec);
}

void PmergeMe::mergeMe(int argc, char **argv)
{
    if (!parse_input(argc, argv))
        return;
    std::cout << "Before: ";
    display_container(_vec);
    //display_container(_deque);

    // Для std::vector
    clock_t start_vec = clock();
    sort_vector(_vec);
    clock_t end_vec = clock();
    double time_vec = (double)(end_vec - start_vec) / CLOCKS_PER_SEC *1000;

    // Для std::deque
    clock_t start_deque = clock();
    sort_deque(_deque);
    clock_t end_deque = clock();
    double time_deque = (double)(end_deque - start_deque) / CLOCKS_PER_SEC *1000;
    
    std::cout << "After:  ";
    display_container(_S);
    //display_container(_S_deque);
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector: " << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << time_deque << " us" << std::endl;
    
}

