#!/usr/bin/env python
import socket
from struct import pack, unpack


MSG_UNKNOWN = (0, "MSG_UNKNOWN")
MSG_SIGN_IN = (1, "MSG_SIGN_IN")
MSG_SIGN_OUT = (2, "MSG_SIGN_OUT")
MSG_DENY = (3, "MSG_DENY")
MSG_LIST = (4, "MSG_LIST")
MSG_TEXT = (5, "MSG_TEXT")
MSG_ACK = (6, "MSG_ACK")
MSG_GETTEXT = (7, "MSG_GETTEXT")
MSG_TEXTFIN = (8, "MSG_TEXTFIN")

MSG_NAMES = dict([MSG_UNKNOWN, MSG_SIGN_IN, MSG_SIGN_OUT, MSG_DENY, MSG_LIST, MSG_TEXT, MSG_ACK, MSG_GETTEXT, MSG_TEXTFIN])


def read_n_bytes(sock, n):
    r = ""
    while len(r) < n:
        r += sock.recv(n-len(r))
        print len(r), ' vs ', n
    return r


class sscp_msg:

    def __init__(selfself, ptype, pid = 0):
        self.type = ptype[0]
        self.id = pid


    def parseHead(self, head):
        self.type, self.id, self.datasize = unpack("3i", head)


    def headerToBin(self, datasize):
        return pack('i', len(text)) + text

    def dataToBin(self):
        return

