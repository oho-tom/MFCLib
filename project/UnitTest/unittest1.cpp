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

			Assert::IsTrue(result);
		}

		/*
		@brief isExist
		@par
			�����F���݂��Ȃ��t�@�C���������ŗ^����
		*/
		TEST_METHOD(isExist_UnExistFile)
		{
			bool result = isExist(_T("C:\\hoge.txt"));
			Assert::IsFalse(result);
		}

		/*
		@brief isExist
		@par
			�����F���݂���t�@�C���������ŗ^����
		*/
		TEST_METHOD(isExist_ExistFile)
		{
			// ���W���[���t�@�C���p�X
			TCHAR temporary_path[_MAX_PATH];
			memset(temporary_path, 0x00, sizeof(temporary_path));
			int size = ::GetModuleFileName(NULL, temporary_path, sizeof(temporary_path));
			Assert::AreNotEqual(size, 0);

			bool result = isExist(temporary_path);
			Assert::IsTrue(result);
		}

		/*
		@brief isExist
		@par
			�����F���݂��Ȃ��f�B���N�g���������ŗ^����
		*/
		TEST_METHOD(isExist_UnExistDirectory)
		{
			bool result = isExist(_T("C:\\hoge"));
			Assert::IsFalse(result);
		}

		/*
		@brief isExist
		@par
			�����F���݂���f�B���N�g���������ŗ^����
		*/
		TEST_METHOD(isExist_ExistDirectory)
		{
			// ���W���[���f�B���N�g��
			CString module_directory;
			GetModuleDirectory(module_directory);

			bool result = isExist(module_directory);
			Assert::IsTrue(result);
		}
	};
}