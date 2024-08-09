#pragma once
#include <functional>

///@brief 双方向リストのクラスです。
///@tparam DataType リストに格納するデータの型です。
template<typename DataType>
class List
{
private:
    ///@brief リストのノードです。
    struct Node
    {
        //! データ
        DataType data;

        //! 前のノードのポインタ
        Node* front = nullptr;

        //! 後ろのノードのポインタ
        Node* back = nullptr;
    };

public:

    ///@brief リストのコンストイテレーターです。
    class ConstIterator
    {
    public:

        ///@brief イテレーターを作成します。
        ConstIterator() = default;

        ///@brief イテレーターを作成します。
        ///@param ptr イテレーターが指すノードのポインタ
        ///@param parent ノードが所属するリストのポインタ
        ConstIterator(Node* ptr, const List* parent);

        ///@brief イテレーターを作成します。
        ///@param iterator コピー元のイテレーター
        ConstIterator(const ConstIterator& iterator);

        ///@brief 別のイテレーターを代入します。
        ///@param iterator 代入するイテレーター
        ///@return イテレーター自身を返します
        ConstIterator& operator =(const ConstIterator& iterator);

        ///@brief イテレーターが指すデータを返します。
        ///@return イテレーターが指すデータを返します。
        ///@detail 何も参照していないイテレーターや末尾イテレーターに対して呼び出した時の動作は未定義
        ///        値の変更は不可能
        const DataType& operator *()const;

        ///@brief 一つ前の要素に戻ります。
        ///@return イテレーター自身
        ///@detail 何も参照していないイテレーターや先頭イテレーターに対して呼び出した時の動作は未定義
        ConstIterator& operator --();

        ///@brief 次の要素に行きます。
        ///@return イテレーター自身
        ///@detail 何も参照していないイテレーターや末尾イテレーターに対して呼び出した時の動作は未定義
        ConstIterator& operator ++();

        ///@brief 一つ前の要素に戻ります。
        ///@return 一つ前に戻る前のイテレーター
        ///@detail 何も参照していないイテレーターや先頭イテレーターに対して呼び出した時の動作は未定義
        ConstIterator operator --(int);

        ///@brief 次の要素に行きます。
        ///@return 次の要素に行く前のイテレーター
        ///@detail 何も参照していないイテレーターや末尾イテレーターに対して呼び出した時の動作は未定義
        ConstIterator operator ++(int);

        ///@brief イテレーター同士が異なっているか調べます。
        ///@param right 比較するイテレーター
        ///@return イテレーター同士が異なっていればtrue 等しければfalseを返します。
        bool operator !=(const ConstIterator& right)const;

        ///@brief イテレーター同士が等しいか調べます。
        ///@param right 比較するイテレーター
        ///@return イテレーター同士が等しければtrue 異なっていればfalseを返します。
        bool operator ==(const ConstIterator& right)const;

    protected:

        //! ノードのポインタ
        Node* m_element = nullptr;

        //! リストのポインタ
        const List* m_parent = nullptr;

        friend List;
    };

    ///@brief リストのイテレーターです。
    class Iterator :public ConstIterator
    {
    public:
        using ConstIterator::ConstIterator;

        ///@brief イテレーターが指すデータを返します。
        ///@return イテレーターが指すデータを返します。
        ///@detail 何も参照していないイテレーターや末尾イテレーターに対して呼び出した時の動作は未定義
        ///        値の変更は可能
        DataType& operator *();
    };

    ///@brief ソートに用いる左右の値を比較する関数の型です。
    ///@return 昇順で並び替えたいときは右の方が大きいときにtrue そうでないときにfalseを返す
    ///        降順で並び替えたいときは左の方が大きいときにtrue そうでないときにfalseを返す
    using CompareFunc = std::function<bool(const DataType&, const DataType&)>;

    ///@brief Listのコンストラクタです。
    List();

    ///@brief Listのデストラクタです。
    ~List();

    ///@brief リストの先頭イテレーターを返します
    ///@return 先頭イテレーター
    Iterator begin();

    ///@brief リストの末尾イテレーターを返します
    ///@return 末尾イテレーター
    Iterator end();

    ///@brief リストの先頭コンストイテレーターを返します
    ///@return 先頭コンストイテレーター
    ConstIterator begin()const;

    ///@brief リストの末尾コンストイテレーターを返します
    ///@return 末尾コンストイテレーター
    ConstIterator end()const;

    ///@brief リストの先頭コンストイテレーターを返します
    ///@return 先頭イテレーター
    ConstIterator constBegin() const;

    ///@brief リストの末尾コンストイテレーターを返します
    ///@return 末尾イテレーター
    ConstIterator constEnd() const;

    ///@brief リストの長さを返します
    ///@return リストの長さ
    size_t size()const;

    ///@brief リストに新たな要素を挿入します。
    ///@param iterator 追加する位置のイテレーター
    ///@param addData 追加するデータ
    ///@return 追加に成功したらtrue 失敗したらfalse
    ///@detail 参照の無いイテレーターや別のリストのイテレーターを渡すと失敗します。
    bool insert(ConstIterator iterator, const DataType& addData);

    ///@brief リストの要素を削除します。
    ///@param iterator 削除する位置のイテレーター
    ///@return 削除に成功したらtrue 失敗したらfalse
    ///@detail 参照の無いイテレーターや別のリストのイテレーター、末尾イテレーターを渡すと失敗します。
    bool remove(ConstIterator iterator);

    ///@brief リストの末尾に要素を追加します。
    ///@param addData 追加するデータ
    void add(const DataType& addData);

    ///@brief クイックソートをします。
    ///@param compare どのように要素を比較するかを指定します。
    ///@sa 実装の参考にしました https://webpia.jp/quick_sort/
    ///@detail move に対応していない型だとパフォーマンスが悪くなります。
    void sort(CompareFunc compare = [](const DataType& left, const DataType& right) {return left < right; });

private:

    ///@brief クイックソートをします。(sortの内部で使います)
    ///@param leftIt 左端のイテレーター
    ///@param rightIt 右端のイテレーター
    ///@param compare どのように要素を比較するかを指定します。
    void quickSort(Iterator leftIt, Iterator rightIt, CompareFunc compare);

    //! 番兵のポインタ
    Node* m_sentinel;

    //! リストの長さ
    size_t m_size = 0;
};

#include"List.inl"
