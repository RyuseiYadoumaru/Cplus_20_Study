/**
 * String_view
 * ���L������������������Q�Ƃ��镶����N���X���`����
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
	* ��������R�s�[���Đ擪�����̃A�h���X���o�͂���v���O����.
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