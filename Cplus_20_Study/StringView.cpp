/**
 * String_view
 * 所有権を持たず文字列を参照する文字列クラスを定義する
 * C++17
 * std::string& = std::string_view
 * 
 * https://cpprefjp.github.io/reference/string_view.html .
 */

#include <string>
#include <string_view>


int main()
{
	/**
	* 文字列をコピーして先頭文字のアドレスを出力するプログラム.
	*/

	std::string_view str_view;
	std::string str = "String";
	std::string str_copy;

	printf("String : %x\n", &str.at(0));

	str_view = str;

	printf("StringView : %x\n", &str_view.at(0));

	str_copy = str;

	printf("StringCopy : %x\n", &str_copy.at(0));

	return 0;
}