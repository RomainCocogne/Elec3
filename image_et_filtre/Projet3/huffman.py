import copy
from collections import deque
import numpy as np


class BinaryTree(object):
    def __init__(self, value=None, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def setValue(self, value):
        self.value = value

    def setLeft(self, subTree):
        self.left = subTree

    def setRight(self, subTree):
        self.right = subTree

    def insertLeft(self, subTree):
        if self.left is None:
            self.setLeft(subTree)
            return
        else:
            raise Exception

    def insertRight(self, subTree):
        if self.right is None:
            self.setRight(subTree)
            return
        else:
            raise Exception

    def isLeaf(self):
        return self.left is None and self.right is None


class HuffmanTree(BinaryTree):
    def __init__(self, value=None, left=None, right=None):
        super(HuffmanTree, self).__init__(value=value, left=left, right=right)
        self.leftCode = 0
        self.rightCode = 1

    def getEncoding(self, encoding=None, path=None):
        """extract a encoding dictionary from the huffman tree
        the keys are the symbols, the values are the corresponding encodings
        DO NOT pass in any parameter"""
        if encoding is None:
            encoding = {}

        if path is None:
            path = deque()

        if self.isLeaf():
            encoding[self.value] = copy.copy(path)
        else:
            path.append(self.leftCode)
            self.left.getEncoding(encoding, path)
            path.pop()

            path.append(self.rightCode)
            self.right.getEncoding(encoding, path)
            path.pop()

        return encoding

def buildHuffmanTree(freqDict):
    shadowDict={HuffmanTree(key):value for key,value in freqDict.items()}

    while len(shadowDict) > 1:
        leastNode = min(shadowDict, key=shadowDict.get)
        leastFreq = shadowDict.pop(leastNode)

        secondNode = min(shadowDict, key=shadowDict.get)
        secondFreq = shadowDict.pop(secondNode)

        tree = HuffmanTree(left=leastNode, right=secondNode)
        shadowDict[tree] = leastFreq + secondFreq

    return list(shadowDict.keys())[0]


def huffmanEncode(encoding, pattern):
    code = ''
    for symbol in pattern:
        code += ''.join([str(x) for x in list(encoding[symbol])])
    return code


def huffmanDecode(tree, code):
    pattern = []
    node = tree
    for digit in code:
        if int(digit) == 0:
            node = node.left
        else:
            node = node.right
        if node.isLeaf():
            pattern.append(node.value)
            node = tree
    return np.array(pattern)

def huffman_compute(dct_block):
    import huffman
    # convert dct_block to integer values
    dct_block = dct_block.astype(int)
    
    # get frequency dictionary
    val, count = np.unique(dct_block, return_counts=True)
    freq_dict = dict(zip(val, count))

    # compute huffman encoding
    huff = huffman.buildHuffmanTree(freq_dict)
    enc_dict = huff.getEncoding()
    return freq_dict, enc_dict
