#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &init)
{
	this->List = init.List;
	this->Vector = init.Vector;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &init)
{
	if (this != &init)
		*this = init;
	return *this;
}

PmergeMe::~PmergeMe()
{}

bool	isInteger(char *str)
{
	char *endptr;
	strtol(str, &endptr, 10);
	if (*endptr != '\0')
	{
		std::cout << "Argument has a non intger value"<< std::endl;
		return false;
	}
	if (errno == ERANGE)
	{
		std::cout << "OverFlow Occured" << std::endl;
		return false;
	}
	return true;
}

void	PmergeMe::Parssing(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (!isInteger(argv[i]))
			throw Erorr();
	}
}

void	PmergeMe::Stack(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::istringstream ss(argv[i]);
		int ret;
		ss >> ret;
		this->List.push_back(ret);
		this->Vector.push_back(ret);
	}
}

//--------------------------vector-------------------------

void mergeV(std::vector<int>& V, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
		L[i] = V[left + i];

    for (int j = 0; j < n2; j++)
		R[j] = V[mid + 1 + j];

	int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
	{
        if (L[i] <= R[j])
	   	{
            V[k] = L[i];
            i++;
        }
	   	else
	   	{
            V[k] = R[j];
            j++;
        }
        k++;
    }
	while (i < n1)
	{
        V[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
	{
        V[k] = R[j];
        j++;
        k++;
    }
}


void insertionSortV(std::vector<int>& V, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int key = V[i];
		int j = i - 1;
		while (j >= left && V[j] > key)
		{
			V[j + 1] = V[j];
			j--;
		}
		V[j + 1] = key;
	}
}

void	mergeInsertionSortV(std::vector<int>& V, int left, int right)
{
	if (left < right)
	{
		if (right - left <= 10)
			insertionSortV(V, left, right);
		else
		{
			int mid = left + (right - left) / 2;
			mergeInsertionSortV(V, left, mid);
			mergeInsertionSortV(V, mid + 1, right);
			mergeV(V, left, mid, right);
		}
	}

}

void	PmergeMe::BeginV()
{
	mergeInsertionSortV(this->Vector, 0, this->Vector.size() - 1);
}

//------------------------List--------------------------

void mergeL(std::list<int>& arr, std::list<int>& left, std::list<int>& right)
{
	std::list<int>::iterator leftIter = left.begin();
	std::list<int>::iterator rightIter = right.begin();

    while (leftIter != left.end() && rightIter != right.end())
	{
        if (*leftIter <= *rightIter)
	   	{
            arr.push_back(*leftIter);
            ++leftIter;
        } 
		else
	   	{
            arr.push_back(*rightIter);
            ++rightIter;
        }
    }
    while (leftIter != left.end())
   	{
        arr.push_back(*leftIter);
        ++leftIter;
    }
    while (rightIter != right.end())
   	{
        arr.push_back(*rightIter);
        ++rightIter;
    }
}

void insertionSortL(std::list<int>& arr)
{
    for (std::list<int>::iterator i = ++arr.begin(); i != arr.end(); ++i)
   	{
        int key = *i;
		std::list<int>::iterator j = i;
        --j;
        while (j != arr.begin() && *j > key)
	   	{
			std::list<int>::iterator PJ = j;
			PJ--;
            *PJ = *j;
            --j;
        }
        if (*j > key)
	   	{
			std::list<int>::iterator PJ = j;
            --PJ;
            *j = *PJ;
			*PJ = key;
        }
    }
}

void mergeInsertionSortL(std::list<int>& L)
{
    if (L.size() <= 10)
        insertionSortL(L);
    else
   	{
		std::list<int> left;
		std::list<int> right;
		std::list<int>::iterator middle = L.begin();
        advance(middle, L.size() / 2);

        left.splice(left.begin(), L, L.begin(), middle);
        right.splice(right.begin(), L, middle, L.end());

        mergeInsertionSortL(left);
        mergeInsertionSortL(right);
        mergeL(L, left, right);
    }
}

void	PmergeMe::BeginL()
{
	mergeInsertionSortL(this->List);
}

void	PmergeMe::Print(int argc, char **argv, double endV, double endL)
{
	if (this->Vector.size() > 10)
	{
		std::cout << "Before: ";
		for (int i = 1; i <= 10; i++)
			std::cout << argv[i] << ' ';
		std::cout << " [...]" << std::endl;
		std::cout << "After: ";
		for (int i = 0; i <= 10; i++)
			std::cout << this->Vector[i] << ' ';
		std::cout << " [...]" << std::endl;
	}
	else 
	{
		std::cout << "Before: ";
		for (int i = 1; i < argc ; i++)
			std::cout << argv[i] << ' ';
		std::cout << std::endl;
		std::cout << "After: ";
		for (size_t i = 0; i < this->Vector.size() ; i++)
			std::cout << this->Vector[i] << ' ';
		std::cout << std::endl;
	}
	std::cout << "Time to process a range of 3000 elements with std::list : " << endL << " us"<< std::endl; 
	std::cout << "Time to process a range of 3000 elements with std::vector : " << endV << " us" << std::endl; 
}


const char *PmergeMe::Erorr::what() const throw()
{
	return "";
}