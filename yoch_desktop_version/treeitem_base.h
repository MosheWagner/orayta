#ifndef TREEITEM_BASE_H
#define TREEITEM_BASE_H


#include <QTreeWidgetItem>
#include <QString>
#include <QList>
#include <QFont>

//#include "bookdisplayer.h"


class BookDisplayer;


//Class containing information about the books and folders.
class BaseNodeItem : public QTreeWidgetItem
{
public:
    enum Nodetype {
        Node,
        Leaf
    };

    enum IconState {
        BLUE,
        HALF,
        GREY
    };

// Name ?
    BaseNodeItem (BaseNodeItem* parent, QString name = "", QString path = "", bool isUserBook = false);
    virtual ~BaseNodeItem();

    bool IsInSearch() const;
    bool IsHidden() const;
    bool IsUserCheckable() const;
    bool IsUserBook() const;

    QString getPath() const;
    IconState getIconState() const;

    virtual QString getTreeDisplayName() const;
    virtual bool isSearchable() const;

    BaseNodeItem* getParent();
    QList<BaseNodeItem*>& getChildren();

    virtual Nodetype nodetype() const = 0;

    virtual void setName(QString name);
    virtual void changeFont( const QFont& );

    void setCheckState(IconState state);


    //Add the pointed book as a child to this folder
    void add_child(BaseNodeItem* child);


    void setSelected(bool);

protected:
    virtual void setIcon();

    //Repaints the icon of this folder, by the state of it's children
    // (Full blue - all selected, Half - some selected and some not, Full grey - all deselected)
    void repaintIcon();

    // recursive function
    void recSetSelection(bool);

    //Pointer to book's parent
    BaseNodeItem* mpParent;

    //List containing pointers to the folders children
    QList<BaseNodeItem*> mvChildren;

    QString mTreeDisplayName;

    //Path of the book's source file
    QString mPath;

    //Icon state of this book (or folder)
    IconState mIconState;

    bool mInSearch;
    bool mIsHidden;
    bool mUserBook;
};




#endif // TREEITEM_BASE_H