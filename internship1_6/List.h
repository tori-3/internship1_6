#pragma once
#include <functional>

///@brief �o�������X�g�̃N���X�ł��B
///@tparam DataType ���X�g�Ɋi�[����f�[�^�̌^�ł��B
template<typename DataType>
class List
{
private:
    ///@brief ���X�g�̃m�[�h�ł��B
    struct Node
    {
        //! �f�[�^
        DataType data;

        //! �O�̃m�[�h�̃|�C���^
        Node* front = nullptr;

        //! ���̃m�[�h�̃|�C���^
        Node* back = nullptr;
    };

public:

    ///@brief ���X�g�̃R���X�g�C�e���[�^�[�ł��B
    class ConstIterator
    {
    public:

        ///@brief �C�e���[�^�[���쐬���܂��B
        ConstIterator() = default;

        ///@brief �C�e���[�^�[���쐬���܂��B
        ///@param ptr �C�e���[�^�[���w���m�[�h�̃|�C���^
        ///@param parent �m�[�h���������郊�X�g�̃|�C���^
        ConstIterator(Node* ptr, const List* parent);

        ///@brief �C�e���[�^�[���쐬���܂��B
        ///@param iterator �R�s�[���̃C�e���[�^�[
        ConstIterator(const ConstIterator& iterator);

        ///@brief �ʂ̃C�e���[�^�[�������܂��B
        ///@param iterator �������C�e���[�^�[
        ///@return �C�e���[�^�[���g��Ԃ��܂�
        ConstIterator& operator =(const ConstIterator& iterator);

        ///@brief �C�e���[�^�[���w���f�[�^��Ԃ��܂��B
        ///@return �C�e���[�^�[���w���f�[�^��Ԃ��܂��B
        ///@detail �����Q�Ƃ��Ă��Ȃ��C�e���[�^�[�▖���C�e���[�^�[�ɑ΂��ČĂяo�������̓���͖���`
        ///        �l�̕ύX�͕s�\
        const DataType& operator *()const;

        ///@brief ��O�̗v�f�ɖ߂�܂��B
        ///@return �C�e���[�^�[���g
        ///@detail �����Q�Ƃ��Ă��Ȃ��C�e���[�^�[��擪�C�e���[�^�[�ɑ΂��ČĂяo�������̓���͖���`
        ConstIterator& operator --();

        ///@brief ���̗v�f�ɍs���܂��B
        ///@return �C�e���[�^�[���g
        ///@detail �����Q�Ƃ��Ă��Ȃ��C�e���[�^�[�▖���C�e���[�^�[�ɑ΂��ČĂяo�������̓���͖���`
        ConstIterator& operator ++();

        ///@brief ��O�̗v�f�ɖ߂�܂��B
        ///@return ��O�ɖ߂�O�̃C�e���[�^�[
        ///@detail �����Q�Ƃ��Ă��Ȃ��C�e���[�^�[��擪�C�e���[�^�[�ɑ΂��ČĂяo�������̓���͖���`
        ConstIterator operator --(int);

        ///@brief ���̗v�f�ɍs���܂��B
        ///@return ���̗v�f�ɍs���O�̃C�e���[�^�[
        ///@detail �����Q�Ƃ��Ă��Ȃ��C�e���[�^�[�▖���C�e���[�^�[�ɑ΂��ČĂяo�������̓���͖���`
        ConstIterator operator ++(int);

        ///@brief �C�e���[�^�[���m���قȂ��Ă��邩���ׂ܂��B
        ///@param right ��r����C�e���[�^�[
        ///@return �C�e���[�^�[���m���قȂ��Ă����true ���������false��Ԃ��܂��B
        bool operator !=(const ConstIterator& right)const;

        ///@brief �C�e���[�^�[���m�������������ׂ܂��B
        ///@param right ��r����C�e���[�^�[
        ///@return �C�e���[�^�[���m�����������true �قȂ��Ă����false��Ԃ��܂��B
        bool operator ==(const ConstIterator& right)const;

    protected:

        //! �m�[�h�̃|�C���^
        Node* m_element = nullptr;

        //! ���X�g�̃|�C���^
        const List* m_parent = nullptr;

        friend List;
    };

    ///@brief ���X�g�̃C�e���[�^�[�ł��B
    class Iterator :public ConstIterator
    {
    public:
        using ConstIterator::ConstIterator;

        ///@brief �C�e���[�^�[���w���f�[�^��Ԃ��܂��B
        ///@return �C�e���[�^�[���w���f�[�^��Ԃ��܂��B
        ///@detail �����Q�Ƃ��Ă��Ȃ��C�e���[�^�[�▖���C�e���[�^�[�ɑ΂��ČĂяo�������̓���͖���`
        ///        �l�̕ύX�͉\
        DataType& operator *();
    };

    ///@brief �\�[�g�ɗp���鍶�E�̒l���r����֐��̌^�ł��B
    ///@return �����ŕ��ёւ������Ƃ��͉E�̕����傫���Ƃ���true �����łȂ��Ƃ���false��Ԃ�
    ///        �~���ŕ��ёւ������Ƃ��͍��̕����傫���Ƃ���true �����łȂ��Ƃ���false��Ԃ�
    using CompareFunc = std::function<bool(const DataType&, const DataType&)>;

    ///@brief List�̃R���X�g���N�^�ł��B
    List();

    ///@brief List�̃f�X�g���N�^�ł��B
    ~List();

    ///@brief ���X�g�̐擪�C�e���[�^�[��Ԃ��܂�
    ///@return �擪�C�e���[�^�[
    Iterator begin();

    ///@brief ���X�g�̖����C�e���[�^�[��Ԃ��܂�
    ///@return �����C�e���[�^�[
    Iterator end();

    ///@brief ���X�g�̐擪�R���X�g�C�e���[�^�[��Ԃ��܂�
    ///@return �擪�R���X�g�C�e���[�^�[
    ConstIterator begin()const;

    ///@brief ���X�g�̖����R���X�g�C�e���[�^�[��Ԃ��܂�
    ///@return �����R���X�g�C�e���[�^�[
    ConstIterator end()const;

    ///@brief ���X�g�̐擪�R���X�g�C�e���[�^�[��Ԃ��܂�
    ///@return �擪�C�e���[�^�[
    ConstIterator constBegin() const;

    ///@brief ���X�g�̖����R���X�g�C�e���[�^�[��Ԃ��܂�
    ///@return �����C�e���[�^�[
    ConstIterator constEnd() const;

    ///@brief ���X�g�̒�����Ԃ��܂�
    ///@return ���X�g�̒���
    size_t size()const;

    ///@brief ���X�g�ɐV���ȗv�f��}�����܂��B
    ///@param iterator �ǉ�����ʒu�̃C�e���[�^�[
    ///@param addData �ǉ�����f�[�^
    ///@return �ǉ��ɐ���������true ���s������false
    ///@detail �Q�Ƃ̖����C�e���[�^�[��ʂ̃��X�g�̃C�e���[�^�[��n���Ǝ��s���܂��B
    bool insert(ConstIterator iterator, const DataType& addData);

    ///@brief ���X�g�̗v�f���폜���܂��B
    ///@param iterator �폜����ʒu�̃C�e���[�^�[
    ///@return �폜�ɐ���������true ���s������false
    ///@detail �Q�Ƃ̖����C�e���[�^�[��ʂ̃��X�g�̃C�e���[�^�[�A�����C�e���[�^�[��n���Ǝ��s���܂��B
    bool remove(ConstIterator iterator);

    ///@brief ���X�g�̖����ɗv�f��ǉ����܂��B
    ///@param addData �ǉ�����f�[�^
    void add(const DataType& addData);

    ///@brief �N�C�b�N�\�[�g�����܂��B
    ///@param compare �ǂ̂悤�ɗv�f���r���邩���w�肵�܂��B
    ///@sa �����̎Q�l�ɂ��܂��� https://webpia.jp/quick_sort/
    ///@detail move �ɑΉ����Ă��Ȃ��^���ƃp�t�H�[�}���X�������Ȃ�܂��B
    void sort(CompareFunc compare = [](const DataType& left, const DataType& right) {return left < right; });

private:

    ///@brief �N�C�b�N�\�[�g�����܂��B(sort�̓����Ŏg���܂�)
    ///@param leftIt ���[�̃C�e���[�^�[
    ///@param rightIt �E�[�̃C�e���[�^�[
    ///@param compare �ǂ̂悤�ɗv�f���r���邩���w�肵�܂��B
    void quickSort(Iterator leftIt, Iterator rightIt, CompareFunc compare);

    //! �ԕ��̃|�C���^
    Node* m_sentinel;

    //! ���X�g�̒���
    size_t m_size = 0;
};

#include"List.inl"
