/* Copyright (c) 2016 Qualcomm Technologies International, Ltd. */
/*   Part of 6.3.2 */
/**
 * \file
 * Implementations of non-autogenerated operator-related trap calls
 */
#include "trap_api/trap_api_private.h"
#include <message.h>
#include <stream.h>
#include <assert.h>
#include "ipc/ipc.h"


#if TRAPSET_OPERATOR

Source StreamSourceFromOperatorTerminal(Operator opid, uint16 terminal)
{
    return SOURCE_FROM_ID((uint16)((uint16)opid + 0x2000 + terminal));
}

Sink StreamSinkFromOperatorTerminal(Operator opid, uint16 terminal)
{
    return SINK_FROM_ID((uint16)((uint16)opid + 0xa000 + terminal));
}

Task MessageOperatorTask(Operator opid, Task task)
{
    /**
     * Operators and sinks are allocated from the same number space.
     * Therefore we can use the same mechanism for forwarding operator
     * messages as we do for sinks.
     */
    return MessageStreamTaskFromSink(SINK_FROM_ID(opid), task);
}

bool OperatorMessage(Operator opid,
                     const uint16 * send_msg, uint16 send_len_words,
                     uint16 * recv_msg, uint16 recv_len_words)
{
    IPC_OPERATOR_MESSAGE op_msg;
    IPC_OPERATOR_MESSAGE_RSP op_msg_rsp;

    op_msg.opid = opid;
    op_msg.send_msg = send_msg;
    op_msg.send_len_words = send_len_words;
    op_msg.recv_len_words = recv_msg ? recv_len_words : 0;
    ipc_send(IPC_SIGNAL_ID_OPERATOR_MESSAGE, &op_msg, sizeof(op_msg));
    (void)ipc_recv(IPC_SIGNAL_ID_OPERATOR_MESSAGE_RSP, &op_msg_rsp);

    if(recv_msg && recv_len_words)
    {
        memcpy(recv_msg, op_msg_rsp.recv_msg, recv_len_words * sizeof(uint16));
        pfree(op_msg_rsp.recv_msg);
    }
    return op_msg_rsp.ret;
}

bool OperatorFrameworkConfigurationGet(uint16 key,
        const uint16 * send_msg, uint16 send_len_words,
        uint16 * recv_msg, uint16 recv_len_words)
{
    IPC_OPERATOR_FRAMEWORK_CONFIGURATION_GET send_prim;
    IPC_OPERATOR_FRAMEWORK_CONFIGURATION_GET_RSP resp_prim;
    send_prim.key = key;
    send_prim.send_msg = send_msg;
    send_prim.send_len_words = send_len_words;
    send_prim.recv_len_words = recv_msg ? recv_len_words : 0;
    ipc_send(IPC_SIGNAL_ID_OPERATOR_FRAMEWORK_CONFIGURATION_GET, &send_prim, sizeof(send_prim));
    (void)ipc_recv(IPC_SIGNAL_ID_OPERATOR_FRAMEWORK_CONFIGURATION_GET_RSP, &resp_prim);

    if(recv_msg && recv_len_words)
    {
        memcpy(recv_msg, resp_prim.recv_msg, recv_len_words * sizeof(uint16));
        pfree(resp_prim.recv_msg);
    }
    return resp_prim.ret;
}

Task MessageOperatorFrameworkTask(Task task)
{
    return trap_api_register_message_task(task, IPC_MSG_TYPE_AUDIO);
}

#endif /* TRAPSET_OPERATOR */

#if TRAPSET_WAKE_ON_AUDIO
bool OperatorFrameworkPreserve(uint16 n_ops, Operator *oplist,
                               uint16 n_srcs, Source *srclist,
                               uint16 n_sinks, Sink *sinklist)
{
    IPC_OPERATOR_FRAMEWORK_PRESERVE send_prim;
    IPC_BOOL_RSP resp_prim;
    uint16 * psrclist = NULL, * psinklist = NULL;
    uint16 i;

    /* Check input arguments */
    if ((n_ops && (oplist == NULL)) ||
        (n_srcs && (srclist == NULL)) ||
        (n_sinks && (sinklist==NULL)))
    {
        return FALSE;
    }

    send_prim.n_ops = n_ops;
    send_prim.oplist = oplist;
    send_prim.n_srcs = n_srcs;
    send_prim.n_sinks = n_sinks;
    if (n_srcs)
    {
        psrclist = pmalloc(sizeof(uint16) * n_srcs);
        for(i=0; i<n_srcs; i++)
        {
            psrclist[i] = SOURCE_TO_ID(srclist[i]);
        }
    }
    if (n_sinks)
    {
        psinklist = pmalloc(sizeof(uint16) * n_sinks);
        for(i=0; i<n_sinks; i++)
        {
            psinklist[i] = SINK_TO_ID(sinklist[i]);
        }
    }
    send_prim.srclist = psrclist;
    send_prim.sinklist = psinklist;
    ipc_send(IPC_SIGNAL_ID_OPERATOR_FRAMEWORK_PRESERVE, &send_prim, sizeof(send_prim));
    assert(!ipc_disallow_high_priority_handler_calls());
    (void)ipc_recv(IPC_SIGNAL_ID_OPERATOR_FRAMEWORK_PRESERVE_RSP, &resp_prim);
    if (psrclist)
    {
        pfree(psrclist);
    }

    if (psinklist)
    {
        pfree(psinklist);
    }
    return resp_prim.ret;
}

bool OperatorFrameworkRelease(uint16 n_ops, Operator *oplist,
                              uint16 n_srcs, Source *srclist,
                              uint16 n_sinks, Sink *sinklist)
{
    IPC_OPERATOR_FRAMEWORK_RELEASE send_prim;
    IPC_BOOL_RSP resp_prim;
    uint16 * psrclist = NULL, * psinklist = NULL;
    uint16 i;

    /* Check input arguments */
    if ((n_ops && (oplist == NULL)) ||
        (n_srcs && (srclist == NULL)) ||
        (n_sinks && (sinklist==NULL)))
    {
        return FALSE;
    }

    send_prim.n_ops = n_ops;
    send_prim.oplist = oplist;
    send_prim.n_srcs = n_srcs;
    send_prim.n_sinks = n_sinks;
    if (n_srcs)
    {
        psrclist = pmalloc(sizeof(uint16) * n_srcs);
        for(i=0; i<n_srcs; i++)
        {
            psrclist[i] = SOURCE_TO_ID(srclist[i]);
        }
    }
    if (n_sinks)
    {
        psinklist = pmalloc(sizeof(uint16) * n_sinks);
        for(i=0; i<n_sinks; i++)
        {
            psinklist[i] = SINK_TO_ID(sinklist[i]);
        }
    }

    send_prim.srclist = psrclist;
    send_prim.sinklist = psinklist;
    ipc_send(IPC_SIGNAL_ID_OPERATOR_FRAMEWORK_RELEASE, &send_prim, sizeof(send_prim));
    assert(!ipc_disallow_high_priority_handler_calls());
    (void)ipc_recv(IPC_SIGNAL_ID_OPERATOR_FRAMEWORK_RELEASE_RSP, &resp_prim);

    if (psrclist)
    {
        pfree(psrclist);
    }
    if (psinklist)
    {
        pfree(psinklist);
    }
    return resp_prim.ret;
}
#endif /* TRAPSET_WAKE_ON_AUDIO */