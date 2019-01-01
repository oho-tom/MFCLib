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
#include <afxext.h>         // MFC �̊g������
#include <atlstr.h>
// c++ header
#include <vector>

/*
@namespace winapi_utility
@brief WindowsAPI���[�e�B���e�B�֐��Q
*/
namespace winapi_utility
{
//! �t�@�C��/�t�H���_�̑��݊m�F
bool isExist(const CString& path);

//! ���W���[���̃f�B���N�g���擾
extern bool GetModuleDirectory(CString& module_directory);

//! �w��f�B���N�g���z���̃t�H���_���X�g�쐬
extern bool CreateFolderList(const CString& target_directory, const bool& isIncludingSubDirectory, std::vector<CString>& folder_list);

//! �p�X������𕪉�����
bool SplitPath(const CString& path, CString& drive, CString& directory, CString& filename, CString& extension);

//! �t�@�C���p�X����t�@�C�����ɑ������镔���𔲂��o��
bool GetFileName(const CString& path, CString& filename, const bool hasExtension);

//! CString�^�����񂩂�A�g���q�ɑ������镔���𔲂��o��
//CString GetExt(const CString& strPathName);

//! CString�^�����񂩂�A�h���C�u���ɑ������镔���𔲂��o��
//CString GetDrive(const CString& strPathName);

//! CString�^�����񂩂�A�t�@�C�����ɑ������镔���𔲂��o��
//CString GetFileName(const CString& strPathName, BOOL bExt);

//! CString�^�����񂩂�A�f�B���N�g���p�X�ɑ������镔���𔲂��o��
//CString GetDirPath(const CString& cstrPath);

};
#endif // MFCLIB_WINAPI_UTILITY_H_
