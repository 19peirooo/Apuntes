import './App.css'
import Board from "./components/Board"
import Winner from './components/Winner';
import { useState, useEffect } from 'react';

function App() {
  const [moves, setMoves] = useState([]);
  const [player, setPlayer] = useState('X');
  const [winner,setWinner] = useState(null);
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

  let board = Array(9).fill('');
  moves.forEach(item => board[item[0]] = item[1]);
  useEffect(() => {
    if (moves.length > 0) check_winner(winningCombos, board, moves);
  }, [moves]);

  const handleClick = (idx) => {
    if (board[idx] || winner) return;

    const next_player = moves.length % 2 ? 'X' : 'O';
    setMoves([...moves, [idx, next_player]]);
    setPlayer(next_player === 'X' ? 'O' : 'X');

    
  };

  const restartGame = () => {
    setMoves([]);
    setWinner(null)
    setPlayer('X');

    board = Array(9).fill('');
    moves.forEach(item => board[item[0]] = item[1]);
  };

  return (
  <>
    {winner && <Winner winner={winner} onOk={restartGame}/>}
    <h1>TicTacToe</h1>
    <p>Player Turn: {player}</p>
    <Board board={board} handleClick={handleClick}/>
    <button id = "restart_btn" onClick={restartGame} disabled={!winner}>Reinciar Juego</button>
  </>
  );
}

export default App
