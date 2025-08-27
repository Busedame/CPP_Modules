#ifndef DATA_HPP
# define DATA_HPP

struct Data
{
	private:
		const char	*str;
		const void	*ptr;
	public:
		Data();
		Data(const Data& oth);
		Data& operator=(const Data& oth);
		~Data();

		const char	*getStr(void);
		const void	*getPtr(void);
};

#endif