class SkipListNode {
    constructor(data) {
        this.data       = data;
        this.level      = -1; // not in list yet
        this.next       = null; // next in the current level
        this.next_level = null; // moves to the next lower level
    }
}

class SkipList {
    constructor(max_level) {
        // this could be better
        this.head       = new SkipListNode(null); // just a empty head node
        this.max_level  = max_level; // max level of the skip list, so it doesent go on for infinity
        this.head.level = max_level;  // highest level

        let tmp = this.head;
        for (let i = (this.max_level - 1); i > 0; i--) { // the head node is present in every level
            tmp.next_level       = new SkipListNode(null);
            tmp.next_level.level = i;
            tmp = tmp.next_level;
        }
    }
    
    #coin_flip() {
        return (Math.floor(Math.random() * 2) == 1)
    }

    insert(node) {
        // move to the end of the list
        // every time the coinflip == true add node to the next level
        // change the node.level to the correct level 
        // then repeat till coinflip == false.
    }
}

let list = new SkipList(5)
for (let tmp = list.head; tmp != null; tmp = tmp.next_level) {
    console.log("level = " + tmp.level);
}

