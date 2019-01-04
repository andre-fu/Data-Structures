class graph:

        def __init__(self):
                self.store = []

        def addVertex(self,n):
                for i in range(n):
                        self.store += [[]]
                if n < 0:
                        return -1

                return len(self.store)

        def addEdge(self, from_index, to_index, directed, weight):
                if from_index >= len(self.store) or to_index >= len(self.store) or weight == 0:
                        return False
                if directed == True:
                        self.store[from_index] += [[to_index,weight]]

                if directed == False:
                        self.store[from_index] += [[to_index, weight]]
                        self.store[to_index] += [[from_index, weight]]

                else:
                        return -1

        def traverse(self, start, typeBreadth):
                if start > len(self.store):
                        return []
                C = []
                counter = 0
                discovered = [False]*len(self.store)
                processed = [False]*len(self.store)

                rval = []
                if start == None and typeBreadth == True:
                        # BREADTH, QUEUE
                        for i in range(0, len(self.store)):
                                if discovered[i] == False:
                                        C.extend(self.store[i])
                                        discovered[i] = True
                                        rval += [i]

                                while len(C) != 0:
                                      
                                        w = C.pop(0)
                                      
                                        try:
                                                if discovered[w[0]] == False:
                                                        rval += [w[0]]
                                                        C.extend(self.store[w[0]])
                                                        discovered[w[0]] = True
                                                        processed[w[0]] = True
                                             
                                        except IndexError:
                                                print w[0]
                        return [rval]
                        
                if start == None and typeBreadth == False:
                        for i in range(0, len(self.store)):
                                 if discovered[i] == False:
                                         C.extend(self.store[i])
                                         discovered[i] = True

                                         rval += [i]

                                 while len(C) != 0:
                                        
                                         w = C.pop(len(C)-1)
                                   
                                         try:
                                                 if discovered[w[0]] == False:
                                                         rval += [w[0]]
                                                         C.extend(self.store[w[0]])
                                                         discovered[w[0]] = True
                                                         processed[w[0]] = True
                                                         
                                         except IndexError:
                                                 print w[0]
                        return rval

                if start != None and typeBreadth == True:
                        # BREADTH, QUEUE
                        for i in range(0, len(self.store)):
                                if discovered[start] == False:
                                        discovered[start] = True
                                        C.extend(self.store[start])
                                        rval += [start]
                                        
                                while len(C) != 0:
                                       
                                        w = C.pop(0)
                                 
                                        try:
                                                  if discovered[w[0]] == False:
                                                          rval += [w[0]]
                                                          C.extend(self.store[w[0]])
                                                          discovered[w[0]] = True
                                                          processed[w[0]] = True
                                                         
                                        except IndexError:
                                                  print w[0]
                         return rval

                if start != None and typeBreadth == False:
                        for i in range(0, len(self.store)):
                                if discovered[start] == False:
                                        discovered[start] = True
                                        C.extend(self.store[start])
                                        rval += [start]
                                        
                                while len(C) != 0:
                                      
                                        w = C.pop(len(C)-1)
                             
                                        try:
                                                  if discovered[w[0]] == False:
                                                          rval += [w[0]]
                                                          C.extend(self.store[w[0]])
                                                          discovered[w[0]] = True
                                                          processed[w[0]] = True
         
                                        except IndexError:
                                                  print w[0]

                        return rval

        def printEdges(self):
                print self.store

        def connectivity(self, vx, vy):
                rval = [False,False]
                list_1 = self.traverse(vx, True)
                if vy in list_1:
                        rval[0] = True
                list_2 = self.traverse(vy, True)
                if vx in list_2:
                        rval[1] = True
                return rval

        def path(self, vx, vy):
                path1 = []
                path2 = []
                visited_list = []
                if (self.connectivity(vx,vy)[0]):
                        start = vx
                        end = vy
                        rval = []
                        C = []
                        for i in range(len(self.store)):
                                                visited_list += [False]

                        if visited_list[start] == False:
                                visited_list[start] = True
                                rval += [[start,None]]
                                for i in range(0,len(self.store[start])):
                                        C += [[self.store[start][i][0],start]]

                        while len(C) != 0:
                                pop_val = C.pop(0)
                                if visited_list[pop_val[0]] == False:
                                        rval += [pop_val]
                                        for i in range(0, len(self.store[pop_val[0]])):
                                                C += [[self.store[pop_val[0]][i][0], pop_val[0]]]
                                        visited_list[pop_val[0]] = True
                        print rval
                        while end is not None:
                                for i in range(0,len(rval)):
                                        if rval[i][0] == end:
                                                path1 = [end] + path1
                                                end = rval[i][1]
                                                break

                if (self.connectivity(vy,vx)[0]):
                        start = vy
                        end = vx
                        rval = []
                        C = []
                        visited_list = []
                        for i in range(len(self.store)):
                                                visited_list += [False]
                        if visited_list[start] == False:
                                visited_list[start] = True
                                rval += [[start,None]]
                                for i in range(0, len(self.store[start])):
                                        C += [[self.store[start][i][0], start]]
                        while len(C) != 0:
                                pop_val = C.pop(0)
                                if visited_list[pop_val[0]] == False:
                                        rval += [pop_val]
                                        for i in range(0, len(self.store[pop_val[0]])):
                                                C += [[self.store[pop_val[0]][i][0], pop_val[0]]]
                                                visited_list[pop_val[0]] = True
                        while end is not None:
                                for i in range(0, len(rval)):
                                        if rval[i][0] == end:
                                                path2 = [end] + path2
                                                end = rval[i][1]
                                                break

                rval_true = [path1,path2]
                return rval_true
                                                                                                       235,1-8       Bot



                        
