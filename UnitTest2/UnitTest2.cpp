#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3/binaryTree.cpp"
#include "../lab3/iterator.cpp"
#include "../lab3/queue.cpp"
#include "../lab3/stack.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		TEST_METHOD(TestInsert)
		{
			binaryTree* tree = new binaryTree(16);
			tree->insert(7);
			tree->insert(1);
			Assert::IsTrue(tree->contains(16) && tree->contains(7) && tree->contains(1));
		}
		TEST_METHOD(TestLeaf)
		{
			binaryTree* tree = new binaryTree(16);
			tree->insert(7);
			tree->insert(1);
			tree->insert(13);
			tree->insert(4);
			tree->insert(3);
			tree->insert(10);
			tree->insert(14);
			tree->insert(6);
			tree->remove(1);
			tree->remove(100);
			Assert::IsTrue(!tree->contains(1));
		}
		TEST_METHOD(TestContains)
		{
			binaryTree* tree = new binaryTree(16);
			tree->insert(7);
			tree->insert(1);
			tree->insert(13);
			tree->insert(4);
			tree->insert(3);
			tree->insert(10);
			tree->insert(14);
			tree->insert(6);
			Assert::IsTrue(tree->contains(6) && !tree->contains(10));
		}
		TEST_METHOD(TestRoot)
		{
			binaryTree* tree = new binaryTree(16);
			tree->insert(7);
			tree->insert(1);
			tree->insert(13);
			tree->insert(4);
			tree->insert(3);
			tree->insert(10);
			tree->insert(14);
			tree->insert(6);
			tree->remove(16);
			Assert::IsTrue(tree->contains(3) && tree->contains(10));
		}
		TEST_METHOD(TestNode2)
		{
			binaryTree* tree = new binaryTree(16);
			tree->insert(7);
			tree->insert(1);
			tree->insert(13);
			tree->insert(4);
			tree->insert(3);
			tree->insert(10);
			tree->insert(14);
			tree->insert(6);
			tree->remove(13);
			Assert::IsTrue(tree->contains(4) && tree->contains(3));
		}
		TEST_METHOD(TestNode1)
		{
			binaryTree* tree = new binaryTree(16);
			tree->insert(7);
			tree->insert(1);
			tree->insert(13);
			tree->insert(4);
			tree->insert(3);
			tree->insert(10);
			tree->insert(14);
			tree->insert(6);
			tree->remove(14);
			Assert::IsTrue(tree->contains(6));
		}
		TEST_METHOD(TestNLR)
		{
			binaryTree* tree = new binaryTree(16);
			tree->insert(7);
			tree->insert(1);
			tree->insert(13);
			tree->insert(4);
			tree->insert(3);
			tree->insert(10);
			tree->insert(14);
			tree->insert(6);
			NLRIterator* iterator = tree->createNLRIterator();
			int arr[9] = { 16, 7, 1, 4, 3, 6, 13, 10, 14 }, i = 0;
			bool isEqual = true;
			while (iterator->hasNext())
			{
				if (iterator->next()->key != arr[i]) isEqual = false;
				i++;
			}
			Assert::IsTrue(isEqual);

		}
		TEST_METHOD(TestBFS)
		{
			binaryTree* tree = new binaryTree(16);
			tree->insert(7);
			tree->insert(1);
			tree->insert(13);
			tree->insert(4);
			tree->insert(3);
			tree->insert(10);
			tree->insert(14);
			tree->insert(6);
			BFSIterator* iterator = tree->createBFSIterator();
			int arr[9] = { 16, 7, 1, 13, 4, 10, 14, 3, 6 }, i = 0;
			bool isEqual = true;
			while (iterator->hasNext())
			{
				if (iterator->next()->key != arr[i]) isEqual = false;
				i++;
			}
			Assert::IsTrue(isEqual);
		}
	};
}
