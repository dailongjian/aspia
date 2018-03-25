//
// PROJECT:         Aspia
// FILE:            host/host_session_file_transfer.h
// LICENSE:         GNU Lesser General Public License 2.1
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_HOST__HOST_SESSION_FILE_TRANSFER_H
#define _ASPIA_HOST__HOST_SESSION_FILE_TRANSFER_H

#include "ipc/pipe_channel.h"
#include "proto/file_transfer_session.pb.h"
#include "protocol/file_depacketizer.h"
#include "protocol/file_packetizer.h"

namespace aspia {

class HostSessionFileTransfer
{
public:
    HostSessionFileTransfer() = default;
    ~HostSessionFileTransfer() = default;

    void Run(const std::wstring& channel_id);

private:
    void OnIpcChannelConnect(uint32_t user_data);
    void OnIpcChannelMessage(const QByteArray& buffer);

    void SendReply(const proto::file_transfer::Reply& reply);
    void OnReplySended();

    void ReadDriveListRequest();
    void ReadFileListRequest(const proto::file_transfer::FileListRequest& request);
    void ReadCreateDirectoryRequest(const proto::file_transfer::CreateDirectoryRequest& request);
    void ReadRenameRequest(const proto::file_transfer::RenameRequest& request);
    void ReadRemoveRequest(const proto::file_transfer::RemoveRequest& request);
    void ReadFileUploadRequest(const proto::file_transfer::UploadRequest& request);
    bool ReadFilePacket(const proto::file_transfer::Packet& file_packet);
    void ReadFileDownloadRequest(const proto::file_transfer::DownloadRequest& request);
    bool ReadFilePacketRequest();

    std::unique_ptr<PipeChannel> ipc_channel_;
    std::shared_ptr<PipeChannelProxy> ipc_channel_proxy_;

    std::unique_ptr<FileDepacketizer> file_depacketizer_;
    std::unique_ptr<FilePacketizer> file_packetizer_;

    DISALLOW_COPY_AND_ASSIGN(HostSessionFileTransfer);
};

} // namespace aspia

#endif // _ASPIA_HOST__HOST_SESSION_FILE_TRANSFER_H
