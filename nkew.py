import pyperclip

class Node(object):
    def __init__(self, number, parent, name=None):
        self.number = number
        self.parent = parent
        self.children = []
        self.name = [name, 'Node_' + str(self.number)][name is None]

    def add_child(self, child):
        self.children.append(child)


class WeightedNewick(object):
    def __init__(self, data):
        self.nodes = []
        self.edges = []
        self.node_weight = {}
        self.construct_tree(data)
        self.name_index = {node.name: node.number for node in self.nodes}

    def construct_tree(self, data):
        data = data.replace(',', ' ').replace('(','( ').replace(')',' )').strip(';').split()
        current_parent = Node(-1, None)
        for item in data:
            if item[0] == '(':
                current_parent = Node(len(self.nodes), current_parent.number)
                self.nodes.append(current_parent)
                if len(self.nodes) > 1:
                    self.nodes[current_parent.parent].add_child(current_parent.number)
                    self.edges.append((current_parent.parent, current_parent.number))

            elif item[0] == ')':
                if len(item) > 1:
                    self.node_weight[current_parent.number] = int(item[item.find(':') + 1:])
                    if len(item) > 2:
                        current_parent.name = item[1:item.find(':')]
                current_parent = self.nodes[current_parent.parent]

            else:
                self.nodes[current_parent.number].add_child(len(self.nodes))
                self.edges.append((current_parent.number, len(self.nodes)))
                self.node_weight[len(self.nodes)] = int(item[item.find(':') + 1:])
                self.nodes.append(Node(len(self.nodes), current_parent.number, item[:item.find(':')]))

    def distance(self, name1, name2):
        if name1 == name2:
            return 0

        branch1 = [self.name_index[name1]]
        branch2 = [self.name_index[name2]]
        while self.nodes[branch1[-1]].parent != -1:
            branch1.append(self.nodes[branch1[-1]].parent)
        while self.nodes[branch2[-1]].parent != -1:
            branch2.append(self.nodes[branch2[-1]].parent)

        return sum([self.node_weight[node] for node in set(branch1) ^ set(branch2)])


f = open(input("Enter input file path: ").strip('"'))
lines = f.read().strip().splitlines()
f.close()

res = []

for i in range(0, len(lines), 3):
    tree = lines[i].strip(';')
    x, y = lines[i + 1].split()
    res.append(WeightedNewick(tree).distance(x, y))

pyperclip.copy(" ".join(map(str, res)))
print(" ".join(map(str, res)))
