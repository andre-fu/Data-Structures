import sys

class binary_tree:

        def __init__(self, val):
                self.store = [val, [], []]

        def AddLeft(self, val):
                if self.store[1] == []:
                        self.store[1] += [val, [], []]
                        return True
                else:
                        return False
        def AddRight(self, val):
                if self.store[2] == []:
                        self.store[2] += [val, [], []]
                        return True
                else:
                        return False

        def inOrder(self, l):
                if (self.store[1] != []):
                        inOrder(self.store[1])
                sys.stdout.write(str(self.store[0]) + " ")
                if (self.store[2] != []):
                        inOrder(self.store[2])
        def Print_DepthFirst(self):
                return self.Traverse(0)

        def Traverse(self, level):
                indent = level*'    '
                print indent + str(self.store[0])
                for i in range(0, len(self.store[1])):
                        self.store[1][i].Traverse(level+1)
                for j in range(0,len(self.store[2])):
                        self.store[2][j].Traverse(level+1)
                return True

