#include "pch.h"
#include "CppUnitTest.h"
#include "ObjectPool.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ObjectPoolTests
{
	TEST_CLASS(ObjectPoolTests)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			ObjectPool<int> Pool1;
			Assert::IsNotNull(&Pool1);
		}

		TEST_METHOD(AddToPool)
		{
			ObjectPool<int> Pool1;
			Assert::IsNotNull(&Pool1);

			int x = 5;
			Pool1.AddToPool(x, 0);

			//ActiveList should be { 5 }
			//Checks ActiveList
			Assert::AreEqual(1, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());

			int y = 7;
			Pool1.AddToPool(y, 0);

			//ActiveList should be { 5, 7 }
			//Checks ActiveList
			Assert::AreEqual(2, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());

			int z = 3;
			Pool1.AddToPool(z, 0);

			//ActiveList should be { 3, 5, 7 }
			//Checks ActiveList
			Assert::AreEqual(3, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());

			int w = 4;
			Pool1.AddToPool(w, 0);

			//ActiveList should be { 4, 3, 5, 7 }
			//Checks ActiveList
			Assert::AreEqual(4, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());
		}

		TEST_METHOD(SetInactive)
		{
			ObjectPool<int> Pool1;
			Assert::IsNotNull(&Pool1);

			int x = 5;
			Pool1.AddToPool(x, 0);

			int y = 7;
			Pool1.AddToPool(y, 0);

			int z = 9;
			Pool1.AddToPool(z, 0);

			//ActivePool should be { 5, 7, 9 }
			Assert::AreEqual(3, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());

			Pool1.SetInactive(x);

			//ActivePool should be { 7, 9 }
			//InactivePool should be { 5 }
			Assert::AreEqual(2, Pool1.ActiveListCount());
			Assert::AreEqual(1, Pool1.InactiveListCount());

			Pool1.SetInactive(y);

			//ActivePool should be { 9 }
			//InactivePool should be { 5, 7 }
			Assert::AreEqual(1, Pool1.ActiveListCount());
			Assert::AreEqual(2, Pool1.InactiveListCount());

			Pool1.SetInactive(z);

			//ActivePool should be { }
			//InactivePool should be { 5, 7, 9 }
			Assert::AreEqual(0, Pool1.ActiveListCount());
			Assert::AreEqual(3, Pool1.InactiveListCount());
		}

		TEST_METHOD(Activate)
		{
			ObjectPool<int> Pool1;
			Assert::IsNotNull(&Pool1);

			int x = 5;
			int y = 7;
			int z = 9;
			Pool1.AddToPool(x, 0);
			Pool1.AddToPool(y, 0);
			Pool1.AddToPool(z, 0);

			//ActivePool should be { 5, 7, 9 }
			//InactivePool should be { }
			Assert::AreEqual(3, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());

			Pool1.SetInactive(x);
			Pool1.SetInactive(y);
			Pool1.SetInactive(z);

			//ActivePool should be { }
			//InactivePool should be { 5, 7, 9 }
			Assert::AreEqual(0, Pool1.ActiveListCount());
			Assert::AreEqual(3, Pool1.InactiveListCount());

			Pool1.Activate(0);
			//ActivePool should be { 5 }
			//InactivePool should be { 7, 9 }
			Assert::AreEqual(1, Pool1.ActiveListCount());
			Assert::AreEqual(2, Pool1.InactiveListCount());

			Pool1.Activate(1);
			//ActivePool should be { 5, 7 }
			//InactivePool should be { 9 }
			Assert::AreEqual(2, Pool1.ActiveListCount());
			Assert::AreEqual(1, Pool1.InactiveListCount());

			Pool1.Activate(0);
			//ActivePool should be { 9, 5, 7 }
			//InactivePool should be { }
			Assert::AreEqual(3, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());
		}

		TEST_METHOD(ActiveListCount)
		{
			ObjectPool<int> Pool1;
			Assert::IsNotNull(&Pool1);

			int x = 5;
			int y = 7;
			int z = 3;
			int w = 4;
			Pool1.AddToPool(x, 0);
			Pool1.AddToPool(y, 0);
			Pool1.AddToPool(z, 0);
			Pool1.AddToPool(w, 0);

			Assert::AreEqual(4, Pool1.ActiveListCount());

			int a = 0;
			int b = 1;
			int c = 2;
			int d = 3;
			Pool1.AddToPool(a, 0);
			Pool1.AddToPool(b, 0);
			Pool1.AddToPool(c, 0);
			Pool1.AddToPool(d, 0);

			Assert::AreEqual(8, Pool1.ActiveListCount());

			Pool1.SetInactive(x);
			Pool1.SetInactive(y);
			Pool1.SetInactive(z);
			Pool1.SetInactive(w);

			Assert::AreEqual(4, Pool1.ActiveListCount());
		
			Pool1.SetInactive(a);
			Pool1.SetInactive(b);
			Pool1.SetInactive(c);
			Pool1.SetInactive(d);

			Assert::AreEqual(0, Pool1.ActiveListCount());
		}

		TEST_METHOD(InactiveListCount)
		{
			ObjectPool<int> Pool1;
			Assert::IsNotNull(&Pool1);

			int x = 5;
			int y = 7;
			int z = 3;
			int w = 4;
			Pool1.AddToPool(x, 0);
			Pool1.AddToPool(y, 0);
			Pool1.AddToPool(z, 0);
			Pool1.AddToPool(w, 0);

			Assert::AreEqual(0, Pool1.InactiveListCount());

			int a = 0;
			int b = 1;
			int c = 2;
			int d = 3;
			Pool1.AddToPool(a, 0);
			Pool1.AddToPool(b, 0);
			Pool1.AddToPool(c, 0);
			Pool1.AddToPool(d, 0);

			Assert::AreEqual(0, Pool1.InactiveListCount());

			Pool1.SetInactive(x);
			Pool1.SetInactive(y);
			Pool1.SetInactive(z);
			Pool1.SetInactive(w);

			Assert::AreEqual(4, Pool1.InactiveListCount());

			Pool1.SetInactive(a);
			Pool1.SetInactive(b);
			Pool1.SetInactive(c);
			Pool1.SetInactive(d);

			Assert::AreEqual(8, Pool1.InactiveListCount());

			Pool1.Activate(x);
			Pool1.Activate(y);
			Pool1.Activate(z);
			Pool1.Activate(w);

			Assert::AreEqual(4, Pool1.InactiveListCount());

			Pool1.Activate(a);
			Pool1.Activate(b);
			Pool1.Activate(c);
			Pool1.Activate(d);

			Assert::AreEqual(0, Pool1.InactiveListCount());
		}

	};
}
