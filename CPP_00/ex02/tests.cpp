// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"

int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t; // Creating an alias for a vector of type Account::t (t is the alias inside Account-class).
	typedef std::vector<int>								  ints_t; // Creates an alias for a vector of int type. A vector is like an array, but can be dynamically resized.
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; // Creates a pair of two iterators. This means that they can be accessed from the same variable, by
	// adding a '.'-sign in front. Later demonstrated: acc_int_t it(acc_begin, dep_begin) -> it.first means acc_begin and it.second means dep_begin.

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; // Initializes an array of amounts.
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) ); // Stores how many elements in the array of of amount in amounts_size.
	accounts_t				accounts( amounts, amounts + amounts_size ); // Initializes a vector, starting from first element to one after last element of the amounts-array.
	accounts_t::iterator	acc_begin	= accounts.begin(); // Tells where the account vector begins.
	accounts_t::iterator	acc_end		= accounts.end(); // Tells where the account vector ends.

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 }; // Same as above, but with deposits.
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 }; // Same as above, but with withdrawals.
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos(); // Make this function! 
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
	// Is used to create a function object that calls a member function on the objects in the range (in this case, calling displayStatus on each Account object).

	for ( acc_int_t it( acc_begin, dep_begin ); // acc_int_t is an alias for a pair between two vector iterators. 
		  it.first != acc_end && it.second != dep_end; // While acc_begin and dep_begin have not reached the end of the vectors.
		  ++(it.first), ++(it.second) ) { // Increment both.

		(*(it.first)).makeDeposit( *(it.second) ); // Make a deposit in the corresponding account.
	}
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); // Exactly the same as before, but with withdrawals instead.

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// // ************************************************************************** //
// // vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// // -*- indent-tabs-mode:t;                                                   -*-
// // -*- mode: c++-mode;                                                       -*-
// // -*- fill-column: 75; comment-column: 75;                                  -*-
// // ************************************************************************** //
