//  GREKO Chess Engine
//  (c) 2002-2015 Vladimir Medvedev <vrm@bk.ru>
//  http://greko.su

//  moves.h: bitboard moves generator
//  modified: 21-Apr-2015

#ifndef MOVES_H
#define MOVES_H

#include "position.h"

struct MoveEntry
{
	MoveEntry() {}
	MoveEntry(Move mv) : m_mv(mv) {}
	Move m_mv;
	int m_value;
};

class MoveList
{
public:
	MoveList() : m_size(0) {}
	MoveEntry& operator[] (size_t n) { return m_data[n]; }
	const MoveEntry& operator[] (size_t n) const { return m_data[n]; }
	void Clear() { m_size = 0; }
	void GenAllMoves(const Position& pos);
	void GenCaptures(const Position& pos, bool genChecks);
	void GenCheckEvasions(const Position& pos);
	Move GetNthBest(int n, Move hashMove = 0);
	int  Size() const { return m_size; }
private:
	void Add(FLD from, FLD to, PIECE piece) { m_data[m_size++].m_mv = Move(from, to, piece); }
	void Add(FLD from, FLD to, PIECE piece, PIECE captured) { m_data[m_size++].m_mv = Move(from, to, piece, captured); }
	void Add(FLD from, FLD to, PIECE piece, PIECE captured, PIECE promotion) { m_data[m_size++].m_mv = Move(from, to, piece, captured, promotion); }
	MoveEntry m_data[256];
	int m_size;
};

#endif
