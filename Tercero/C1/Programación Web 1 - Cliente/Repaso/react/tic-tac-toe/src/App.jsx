import { useState, useEffect } from 'react'
import './App.css'
import Board from './components/Board'
import Winner from './components/Winner'

function App() { 

  const [player,setPlayer] = useState('X')
  const [moves,setMoves] = useState([])
  const [winner,setWinner] = useState('')

  const winningCombos = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
  ];

  let board=Array(9).fill('');
  moves.forEach(item => board[item[0]] = item[1])
  useEffect(() => {
    if (moves.length > 0) check_winner(winningCombos, board, moves);
  }, [moves]);

  const check_player = (choices,board,player) => {
    return choices.some((item) => (board[item[0]] === board[item[1]] && board[item[1]] === board[item[2]] && board[item[0]] === player));
  }

  const check_winner = (choices,board,moves) => {
    if (check_player(choices,board,'X')) {
      setWinner('X')
    } else if (check_player(choices,board,'O')) {
      setWinner('O')
    } else {
      setWinner(moves.length === 9 ? "Empate":null)
    }
  }

  const handleClick = (idx) => {
    if (board[idx] || winner) return;

    setMoves([...moves,[idx,player]])
    let next_player = player === 'X' ? 'O':'X'
    setPlayer(next_player)
  }

  const restartGame = () => {
    setMoves([])
    setPlayer('X')
    setWinner('')
  }

  return (
    <>
      <h1>Tic Tac Toe</h1>
      <h2>Turno de Jugador {player}</h2>
      <Board board={board} handleClick={handleClick}></Board>
      {winner && <Winner winner={winner} onOk={restartGame}></Winner>}
    </>
  )
}

export default App
