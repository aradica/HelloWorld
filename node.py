#1D
class Node:

    def __init__(self, value, i=None, o=None):
        self.value = value
        self.i = None
        self.o = None

    def __repr__(self):
        if self.i == None:
            i = ""
            ni = ""
        else:
            i = self.i.value
            ni = "..."
        if self.o == None:
            o = ""
            no = ""
        else:
            o = self.o.value
            no = "..."

        return "{}[{}]<--->[{}]<--->[{}]{}".format(ni, i, self.value, o, no)

    def connectTo(self, other):
        self.o = other
        other.i = self
    
    def connectNode(self, other):
        self.i = other
        other.o = self

    def disconnectInput(self):
        self.i.o = None
        self.i = None

    def disconnectOutput(self):
        self.o.i = None
        self.o = None
        

    
    def sendValue(self):
        if self.o != None:
            self.o.value = self.value
    
    #mode: 1, -1
    def propagateValue(self, mode):
        if mode == 1:
            if self.o != None:
                self.o.value = self.value
                self.o.propagateValue(mode)

        elif mode == -1:
            if self.i != None:
                self.i.value = self.value
                self.i.propagateValue(mode)
        
        else:
            return "Error: invalid mode."

    def activate(self):
        print(self.value)

    #mode 1, -1
    def propagateActivation(self, mode):
        if mode == 1:
            self.activate()
            if self.o != None:
                self.o.propagateActivation(mode)

        elif mode == -1:
            self.activate()
            if self.i != None:
                self.i.propagateActivation(mode)

        else:
            return "Error: invalid mode."

if __name__ == "__main__":
    n1, n2, n3 = Node(1), Node(2), Node(3)
    n1.connectTo(n2)
    n2.connectTo(n3)
    print(n1)
    n3.propagateActivation(-1)
    n3.propagateValue(-1)
    n3.propagateActivation(-1)
    n1.value = 10
    n1.propagateValue(1)
    n1.propagateActivation(1)