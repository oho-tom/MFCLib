/*
 @file winapi_utility.h
 @brief WindowsAPI���[�e�B���e�B�֐��w�b�_�t�@�C��
*/
#ifndef MFCLIB_WINAPI_UTILITY_H_
#define MFCLIB_WINAPI_UTILITY_H_

//------------------------------------------------------------------------------
// include
//------------------------------------------------------------------------------
// MFC header
#include <atlstr.h>
// c++ header
#include <vector>

/*
@namespace winapi_utility
@brief WindowsAPI���[�e�B���e�B�֐��Q
*/
namespace winapi_utility
{
//! ���W���[���̃f�B���N�g���擾
extern bool GetModuleDirectory(CString& module_directory);

//! �w��f�B���N�g���z���̃t�H���_���X�g�쐬
extern bool CreateFolderList(const CString& target_directory, const bool& isIncludingSubDirectory, std::vector<CString>& folder_list);
};
#endif // MFCLIB_WINAPI_UTILITY_H_
