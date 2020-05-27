#include <iostream>

template <typename Vtype>
class BinTree {

protected:
    
    /*

- ctor
- copy ctor
- dtor

- node subclass

*/
    class Node {
    private:

        Vtype value;
        Node *left;
        Node *right;
        int count = 0;

        // KESOBB publicba + DTOR -> ha van pointer
        Node(const Node &); // copy ctor lvalue tiltas (private)
        Node & operator=(const Node &); // masolo lvalue ertekadas ket node kozott
        Node(const Node &&); // move ctor rvalue tiltas (private)
        Node &operator=(const Node &&); // masolo rvalue ertekadas ket node kozott

    public:
        Node(Vtype value): value(value),left(nullptr),right(nullptr) {}
        Vtype getValue(){return value;}
        Node * leftChild(){return left;}
        Node * rightChild(){return right;}
        void setleftChild(Node * node){left = node;}
        void setrightChild(Node * node){right = node;}
        int getCount(){return count;}
        void incCount(){++count;}
    };

    Node *root;
    Node *currentNode;
    int depth = 0;

private:
 // KESOBB publicba + DTOR -> ha van pointer
    // BinTree(const BinTree &);            // copy ctor lvalue tiltas (private)
    // BinTree &operator=(const BinTree &); // masolo lvalue ertekadas ket BinTree kozott
    // BinTree(const BinTree &&);           // move ctor rvalue tiltas (private)
    // BinTree &operator=(const BinTree &&); // masolo rvalue ertekadas ket BinTree kozott
   

public:
    BinTree(Node *root = nullptr,Node * currentNode = nullptr): root(root),currentNode(currentNode){
    	std::cout<<"BT ctor"<<std::endl;
    }
    ~BinTree()
    {
    	std::cout<<"BT dtor"<<std::endl;
    	deltree(root);
    }

     // KESOBB publicba + DTOR -> ha van pointer
    BinTree(const BinTree & old){
    	std::cout<<"BT copy ctor"<<std::endl;
    	root = cp(old.root,old.currentNode); 
    }       
    BinTree &operator=(const BinTree &){
    	std::cout<<"BT copy assignment"<<std::endl;
    	BinTree tmp{old};
    	std::swap(*this,tmp);
    	return *this;
    }
    BinTree(BinTree && old){
    	std::cout<<"BT move ctor"<<std::endl;
    	root = nullptr
    	*this = std::move(old);
    	
    }     
    BinTree &operator=(BinTree && old){
    	std::cout<<"BT move assignment"<<std::endl;
    	std::swap(old.root,root);
    	std::swap(old.currentNode,root);

    	return *this;
    } 

    BinTree & operator<<(Vtype value);
    void print(){print(root,std::cout);}
    void print(Node * node,std::ostream & os);
    void deltree(Node * node);

};

template <typename Vtype>
class LZWTree : public BinTree<Vtype>{

public:
    LZWTree() : BinTree<Vtype>(new typename BinTree<Vtype>::Node('/'))
    {
    	this->currentNode = this->root;
    }
    LZWTree & operator<<(Vtype value);
};

template <typename Vtype>
BinTree<Vtype> & BinTree<Vtype>::operator<<(Vtype value)
	{
		if(!currentNode){
			root = currentNode = new Node(value);
		}
		else if(currentNode->getValue() == value){
			currentNode->incCount();
		}
		else if(currentNode->getValue() > value){
			if(!currentNode->leftChild())
			{
				currentNode->setleftChild(new Node(value));
			}
			else
			{
				currentNode = currentNode->leftChild();
				*this << value;
			}
		}
		else if(currentNode->getValue() < value){
			if(!currentNode->rightChild())
			{
				currentNode->setrightChild(new Node(value));
			}
			else
			{
				currentNode->leftChild();
				*this << value;
			}
			
		}

		currentNode = root;

		return *this;
	}

template <typename Vtype>
LZWTree<Vtype> & LZWTree<Vtype>::operator<<(Vtype value)
	{

	if(value == '0') {
		if (!this->currentNode->leftChild())
		{
			typename BinTree<Vtype>::Node * node = new typename BinTree<Vtype>::Node(value);
			this->currentNode->setleftChild(node);
			this->currentNode = this->root;
			// ?? typename BinTree<Vtype>::Node->setleftChild(new typename BinTree<Vtype>::Node(value));
		}
		else
		{
			this->currentNode = this->currentNode->leftChild();
		}
	}
	else if(value == '1'){
		if (!this->currentNode->rightChild())
		{
			typename BinTree<Vtype>::Node * node = new typename BinTree<Vtype>::Node(value);
			this->currentNode->setrightChild(node);
			this->currentNode = this->root;
			// ?? typename BinTree<Vtype>::Node->setleftChild(new typename BinTree<Vtype>::Node(value));
		}
		else
		{
			this->currentNode = this->currentNode->rightChild();
		}

		
		}
		return *this;
	}

template <typename Vtype>
Node * BinTree<Vtype>::cp(Node* node ,Node * currentNode)
{
	Node * newNode = nullptr;

	if(node)
	{
		newNode =  new Node(node->getValue());
		newNode.setleftChild(cp(node->leftChild(),currentNode));
		newNode.setrightChild(cp(node->rightChild(),currentNode));

		if (node == currentNode){
			this->currentNode = newNode;
		}
	}

	return newNode;
}

template <typename Vtype>
void BinTree<Vtype>::print(Node*node,std::ostream & os )
{
	if(node)
	{
		++depth;
		print(node->leftChild(),os);
		for (int i=0;i < depth;++i)
		{
			os<<"---";
		}
		os << node->getValue()<<std::endl; //<< " ("<<depth<<") "<<node->getCount()<<"."<<std::endl;
		print(node->rightChild(),os);
		--depth;
	}
}

template <typename Vtype>
void BinTree<Vtype>::deltree(Node*node)
{
	if(node)
	{
		deltree(node->leftChild());
		deltree(node->rightChild());
		delete node;
	}
}


int main(int argc,char** argv,char** env)
{
    BinTree<int> MyBinaryTree;
    
    // MyBinaryTree << 7 << 1 << 9 << 6 << 6 << 10 << 7 << 9 << 9 << 3 << 4 <<5 <<1;

    // MyBinaryTree.print();

    std::cout<<std::endl;

    LZWTree<char> MyLZWTree;

    MyLZWTree <<'0'<<'1'<<'1'<<'1'<<'1'<<'0'<<'0'<<'1'<<'0'<<'0'<<'1'<<'0'<<'0'<<'1'<<'0'<<'0'<<'0'<<'1'<<'1'<<'1';

    LZWTree<char> MyLZWTree2{MyLZWTree}; //másoló ctor
    LZWTree<char> MyLZWTree3;
    MyLZWTree3 << '0' << '0'<< '0'<< '0'<< '0';
    MyLZWTree = MyLZWTree3;

}
