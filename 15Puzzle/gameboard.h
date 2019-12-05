#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QAbstractListModel>
#include <vector>

class GameBoard : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int dimension READ dimension CONSTANT)
    Q_PROPERTY(QString hiddenElementValue READ hiddenElementQString CONSTANT)

public:
    using Position = std::pair<size_t, size_t>;
    static constexpr size_t defaultPuzzleDimesion {4};

    GameBoard(const size_t boardDimension = defaultPuzzleDimesion, QObject* parent = nullptr);

    struct Tile{
        size_t value {};
        Tile& operator=(const size_t newValue){
            value = newValue;
            return *this;
        }

        bool operator== (const size_t other){
            return other == value;
        }
    };

    Q_INVOKABLE bool move(int index);

    size_t dimension() const;
    size_t boardSize() const;
    QString hiddenElementQString() const;

    int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    Position getRowCol(size_t index) const;


private:
    void shuffle();
    bool isPositionValid(const size_t position) const;
    bool isBoardValid() const;

    std::vector<Tile> m_rawBoard;
    const size_t m_dimension;
    const size_t m_boardSize;
};

#endif // GAMEBOARD_H
