template <int W, int H>
Matrix<W, H>::Matrix() : _width(W), _height(H)
{
  std::fill(_array.begin(), _array.end(), 0);
}
template <int W, int H>
int& Matrix<W, H>::at(int x, int y)
{
    assert(x < _width && y < _height && "variable can't be superior to matrix size");
    return _array[x + y * _width];
}
template <int W, int H>
inline int Matrix<W, H>::width() const
{
    return _width;
}
template <int W, int H>
inline int Matrix<W, H>::height() const
{
    return _height;
}
