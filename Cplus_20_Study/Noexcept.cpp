//　noexcept
//　C++11で導入された。
//　throwキーワードの例外仕様の代替
//　関数がどの例外を送出する可能性があるか列挙するのではなく
//　例外の可能性のあるかないかを指定する
//　例外を送出する可能性がある関数：noexcept(false)
//　例外を送出する可能性がない関数：noexcept(true) or noexcept
//　https://cpprefjp.github.io/lang/cpp11/noexcept.html


class Player
{
	float hp = 0.0f;
public:
	//例外を出さない
	float getHP() const noexcept
	{
		return hp;
	}

};