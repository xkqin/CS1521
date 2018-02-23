template <typename ItemType>
Node<ItemType>::Node()
  : next(nullptr) {
}

template <typename ItemType>
Node<ItemType>::Node(const ItemType& anItem)
  : item(anItem),
    next(nullptr) {
    }

template <typename ItemType>
Node<ItemType>::Node(const ItemType& anItem,
                     Node<ItemType>* nextNodePtr)
  : item(anItem),
    next(nextNodePtr) {
    }

template <typename ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {

  item = anItem;
}

template <typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {

  next = nextNodePtr;
}

template <typename ItemType>
ItemType Node<ItemType>::getItem() const {

  return item;
}

template <typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {

  return next;
}
