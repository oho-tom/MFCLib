#include "stdafx.h"
#include "CppUnitTest.h"
#include "winapi_utility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace winapi_utility;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: �e�X�g �R�[�h�������ɑ}�����܂�
			CString module_directory;
			GetModuleDirectory(module_directory);
		}

	};
}