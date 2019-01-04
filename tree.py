class tree:
        def __init__(self,x):
                self.store = [x, []]

        def AddSuccessor(self,x):
                self.store[1] = self.store[1] + [x]
                return True

        def Print_DepthFirst(self):
                return self.Traverse(0)

        def Traverse(self, level):
                indent = level*'    '
                print indent + str(self.store[0])
                for i in range(0, len(self.store[1])):
                        self.store[1][i].Traverse(level+1)
                return True

        def Get_LevelOrder(self):
                return_list = []
                return_list = self.Traverse2(0, return_list)
                print return_list

        def Traverse2(self,level,l):
                l.append(self.store[0])
                for i in range(0,len(self.store[1])):
                        self.store[1][i].Traverse2(level+1, l)
                return l


        def enqueue(self, root):
                self.l = []
                self.l.append(root)
        def dequeue(self):
                x = self.l[0]
                self.l = self.l[1:]
                return x
        def converttobinary(self):
                Q = self.store
                newlist = self.store
                while newlist != []:
                        print newlist[0]
                        newlist = newlist[1]
                        for element in newlist:
                                newlist += [element]
                return True
