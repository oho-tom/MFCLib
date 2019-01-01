#include "stdafx.h"
#include "CppUnitTest.h"
#include "winapi_utility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace winapi_utility;

namespace UnitTest
{		
	TEST_CLASS(UT_winapi_utility)
	{
	public:

		/*
		@brief GetModuleDirectory
		@par
			�����F�擾�����f�B���N�g�������݂��邩
		*/
		TEST_METHOD(GetModuleDirectory_ResultCheck)
		{
			CString module_directory;
			GetModuleDirectory(module_directory);

			bool result = isExist(module_directory);

			Assert::AreEqual(result, true);
		}

		/*
		@brief isExist
		@par
			�����F���݂��Ȃ��t�@�C���������ŗ^����
		*/
		TEST_METHOD(isExist_UnExistFile)
		{
			bool result = false;

			// ���W���[���t�@�C���p�X
			TCHAR temporary_path[_MAX_PATH];
			memset(temporary_path, 0x00, sizeof(temporary_path));
			::GetModuleFileName(NULL, temporary_path, sizeof(temporary_path));

			// ���W���[���f�B���N�g��
			CString module_directory;
			GetModuleDirectory(module_directory);

			// ���݂��Ȃ��t�@�C��
			result = isExist(_T("C:\\hoge.txt"));
			Assert::AreEqual(result, false);
			
			// ���݂���t�@�C��
			result = isExist(temporary_path);
			Assert::AreEqual(result, true);

			// ���݂��Ȃ��f�B���N�g��
			result = isExist(_T("C:\\hoge"));
			Assert::AreEqual(result, false);

			// ���݂���f�B���N�g��
			result = isExist(module_directory);
			Assert::AreEqual(result, true);
		}
	};
}