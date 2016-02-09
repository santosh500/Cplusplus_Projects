/**
File Name: BinarySearchTree.hpp 
Author: Paul Charles
Date: 11.11.2015
Purpose: File contains the BinarySearchTree functions
**/
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root = nullptr;

}
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
    if(other.m_root==nullptr)
    {
        m_root=nullptr;
    }
    else
    {
        m_root=new Node<T>(*(other.m_root));
    }
    
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    
    
    if(isEmpty())
    {
        
    }
    else
    {
	deleteTree(m_root);
        m_root=nullptr;          
    }
}

template <typename T>
BSTI<T>* BinarySearchTree<T>::clone()
{
    if(m_root==nullptr)
    {
        BinarySearchTree<T>* a=new BinarySearchTree();  
        return a;
    }
    else
    {
        
        BinarySearchTree<T>* b=new BinarySearchTree(*this);
        return b;        
    }
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const
{
	if (m_root == nullptr)
	{
           
            return(true);

	}
	else
	{
		
            return(false);

	}
}

template <typename T>
bool BinarySearchTree<T>::add(T value)
{
	return add(value, m_root);
}

template <typename T>
bool BinarySearchTree<T>::search(T value)const
{

	return search(value, m_root);
}

template <typename T>
vector<T> BinarySearchTree<T>::treeToVector(Order order)const
{
    vector<int> vec;
    treeToVector(m_root, order, vec);
    return vec;
}
//private methods

template <typename T>
void BinarySearchTree<T>::treeToVector(Node<T>* subtree, Order order, vector<T>& vec)const
{

    if(order==PRE_ORDER)
    {
        vec.push_back(subtree->getValue());

        if (subtree->getLeft() != nullptr)
        {
             treeToVector(subtree->getLeft(), PRE_ORDER, vec);                    
        }
        if ((subtree->getRight()) != nullptr)
        {
             treeToVector(subtree->getRight(), PRE_ORDER, vec);  
        }   
    }
    else if(order==IN_ORDER)
    {
        if(subtree->getLeft() != nullptr)
        {
            
            treeToVector(subtree->getLeft(),IN_ORDER,vec);
            
        }
        vec.push_back(subtree->getValue());
        if ((subtree->getRight()) != nullptr)
        {
            treeToVector(subtree->getRight(), IN_ORDER,vec);  
        }
    }
    else if(order==POST_ORDER)
    {
        if(subtree->getLeft() != nullptr)
        {
            treeToVector(subtree->getLeft(),POST_ORDER, vec);
        }
        
        if(subtree->getRight() != nullptr)
        {
            treeToVector(subtree->getRight(), POST_ORDER, vec);  
        }
        vec.push_back(subtree->getValue());
    }
}
template <typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subtree)
{
	
	bool bvalue = false;
	if (isEmpty())
	{
		Node<T>* o = new Node<T>();
		o->setValue(value);
		o->setLeft(nullptr);
		o->setRight(nullptr);
		m_root = o;
		bvalue = true;
	}
	else
	{
		if (value < subtree->getValue())
		{
			if (subtree->getLeft() != nullptr)
			{
				add(value, subtree->getLeft());

			}
			else 
			{
                                Node<T>* k = new Node<T>();
                                k->setValue(value);  
				subtree->setLeft(k);
				k->setLeft(nullptr);
				k->setRight(nullptr);
				bvalue = true;
			}

		}
		else if (value > subtree->getValue())
		{
			if (subtree->getRight() != nullptr)
			{
				add(value, subtree->getRight());

			}
			else
			{
                                Node<T>* k = new Node<T>();
                                k->setValue(value);
				subtree->setRight(k);
				k->setLeft(nullptr);
				k->setRight(nullptr);
				bvalue = true;
			}
		}


	}
	return bvalue;
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subtree)
{
        if(subtree->getLeft() != nullptr)
        {
            deleteTree(subtree->getLeft());
        }
        
        if(subtree->getRight() != nullptr)
        {
            deleteTree(subtree->getRight());  
        }
        delete subtree;
        subtree=nullptr;
}

template <typename T>
bool BinarySearchTree<T>::search(T value, Node<T>* subtree)const
{

	if (isEmpty())
	{
		return false;
	}
	else if (value == m_root->getValue())
	{
		return true;
	}
	else
	{
		if (value < subtree->getValue())
		{
			if (subtree->getLeft() != nullptr)
			{
				if ((subtree->getLeft())->getValue() == value)
				{
					return true;
	
				}
				else
				{
					search(value, subtree->getLeft());	
				}

			}
			else
			{
				return false;

			}

		}
		else if (value > subtree->getValue())
		{

			if (subtree->getRight() != nullptr)
			{
				if ((subtree->getRight())->getValue() == value)
				{
					return true;

				}
				else
				{
					search(value, subtree->getRight());
				}

			}
			else
                        {

				return false;

			}


		}

	}

}

template <typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order)const
{
    if(order==PRE_ORDER)
    {
                    cout << subtree->getValue() << endl;
                    if (subtree->getLeft() != nullptr)
                    {
                        printTree(subtree->getLeft(), PRE_ORDER);                    

                    }
                    if ((subtree->getRight()) != nullptr)
                    {
                        printTree(subtree->getRight(), PRE_ORDER);  

                    }   
    }
    else if(order==IN_ORDER)
    {
        if(subtree->getLeft() != nullptr)
        {
            
            printTree(subtree->getLeft(),IN_ORDER);
            
        }
        cout << subtree->getValue() << endl;
        if ((subtree->getRight()) != nullptr)
        {
            printTree(subtree->getRight(), IN_ORDER);  
        }
    }
    else if(order==POST_ORDER)
    {
        if(subtree->getLeft() != nullptr)
        {
            printTree(subtree->getLeft(),POST_ORDER);
        }
        
        if(subtree->getRight() != nullptr)
        {
            printTree(subtree->getRight(), POST_ORDER);  
        }
        cout << subtree->getValue() << endl;
    }
}

template <typename T>
void BinarySearchTree<T>::printTree(Order order)const
{
    if(order==PRE_ORDER)
    {
        printTree(m_root, order);
    }
    else if(order==IN_ORDER)
    {
        printTree(m_root, order);
    }
    else if(order==POST_ORDER)
    {
        printTree(m_root, order);
    }
}
