/*
 @file winapi_utility.cpp
 @brief WindowsAPI���[�e�B���e�B�֐��w�b�_�t�@�C��
*/

//------------------------------------------------------------------------------
// include
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "winapi_utility.h"

//------------------------------------------------------------------------------
// ���������[�N���o�錾
//------------------------------------------------------------------------------
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace winapi_utility
{
/*
 @brief ���W���[���̃f�B���N�g���擾
 @param[out] module_directory ���W���[���̃f�B���N�g��
 @retval true ����
 @retval false ���s
*/
bool GetModuleDirectory(CString& module_directory)
{
	TCHAR temporary_path[_MAX_PATH];
	memset(temporary_path, 0x00, sizeof(temporary_path));
	::GetModuleFileName(NULL, temporary_path, sizeof(temporary_path));
	// �Ō��\�̈ʒu�����߂�
	TCHAR* last_backslash = _tcsrchr(temporary_path, '\\');
	// ������NULL����������
	if (last_backslash != NULL)
		temporary_path[(int)(last_backslash - temporary_path)] = 0x00;

	module_directory = temporary_path;

	return true;
}

bool CreateFolderList(const CString& target_directory, const bool& isIncludingSubDirectory, std::vector<CString>& folder_list)
{
	//----------------------------------------------------------------------
	// �w��t�H���_�ȉ��̃t�H���_���X�g���擾
	//----------------------------------------------------------------------
	WIN32_FIND_DATA find_data;
	CString target;
	if (target_directory.Right(0) != '\\')
		target = target_directory + _T("\\*");
	else
		target = target_directory + '*';

	HANDLE folder_handle = FindFirstFile(target, &find_data);
	//----------------------------------------------------------------------
	// �擾�����ꗗ�̐������J�Ԃ�
	//----------------------------------------------------------------------
	BOOL isFound = (folder_handle != INVALID_HANDLE_VALUE);
	while (isFound)
	{
		//------------------------------------------------------------------
		// �t�H���_�ł��邩����
		//------------------------------------------------------------------
		if (!(find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			// ���̏���
			isFound = FindNextFile(folder_handle, &find_data);
			continue;
		}
		CString folder_name(find_data.cFileName);

		//------------------------------------------------------------------
		// �����ȃt�H���_�����O
		//------------------------------------------------------------------
		if (folder_name == _T(".") || folder_name == _T(".."))
		{
			// ���̏���
			isFound = FindNextFile(folder_handle, &find_data);
			continue;
		}

		// �����p�̕���"\\*"���폜
		if (target.Right(0) == '*')
			target.TrimRight();
		if (target.Right(0) == '\\')
			target.TrimRight();

		//------------------------------------------------------------------
		// �T�u�t�H���_�p�X�쐬
		//------------------------------------------------------------------
		CString sub_folder = target + '\\' + folder_name;
		//------------------------------------------------------------------
		// �t�H���_�p�X���o�͕ϐ��ɒǉ�
		//------------------------------------------------------------------
		folder_list.push_back(sub_folder);
		//------------------------------------------------------------------
		// �T�u�t�H���_�ȉ�����
		//------------------------------------------------------------------
		if(isIncludingSubDirectory)
			CreateFolderList(sub_folder, true, folder_list);

		//------------------------------------------------------------------
		// ���̏���
		//------------------------------------------------------------------
		isFound = FindNextFile(folder_handle, &find_data);
	}
	//----------------------------------------------------------------------
	// �����n���h���N���[�Y
	//----------------------------------------------------------------------
	FindClose(folder_handle);

	return true;
}

};