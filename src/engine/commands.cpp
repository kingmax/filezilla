#include "FileZilla.h"

CConnectCommand::CConnectCommand(const CServer &server)
{
	m_Server = server;
}

const CServer CConnectCommand::GetServer() const
{
	return m_Server;
}

CListCommand::CListCommand(bool refresh /*=false*/)
	: m_refresh(refresh)
{
}

CListCommand::CListCommand(CServerPath path, wxString subDir /*=_T("")*/, bool refresh /*=false*/)
	: m_refresh(refresh)
{
	m_path = path;
	m_subDir = subDir;
}

CServerPath CListCommand::GetPath() const
{
	return m_path;
}

wxString CListCommand::GetSubDir() const
{
	return m_subDir;
}

bool CListCommand::Refresh() const
{
	return m_refresh;
}

CFileTransferCommand::CFileTransferCommand()
{
}

CFileTransferCommand::CFileTransferCommand(const wxString &localFile, const CServerPath& remotePath, const wxString &remoteFile, bool download)
{
	m_localFile = localFile;
	m_remotePath = remotePath;
	m_remoteFile = remoteFile;
	m_download = download;
}

wxString CFileTransferCommand::GetLocalFile() const
{
	return m_localFile;
}

CServerPath CFileTransferCommand::GetRemotePath() const
{
	return m_remotePath;
}

wxString CFileTransferCommand::GetRemoteFile() const
{
	return m_remoteFile;
}

bool CFileTransferCommand::Download() const
{
	return m_download;
}

CRawCommand::CRawCommand(const wxString &command)
{
	m_command = command;
}

wxString CRawCommand::GetCommand() const
{
	return m_command;
}

CDeleteCommand::CDeleteCommand(const CServerPath& path, const wxString& file)
{
	m_path = path;
	m_file = file;
}

CRemoveDirCommand::CRemoveDirCommand(const CServerPath& path, const wxString& subDir)
{
	m_path = path;
	m_subDir = subDir;
}
