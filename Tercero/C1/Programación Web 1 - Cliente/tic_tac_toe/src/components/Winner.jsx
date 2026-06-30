import {useRef, useEffect} from 'react'

export default function Winner({winner,onOk}) {
    const ref = useRef(null);
    const text = (winner !== 'Empate') ? `El ganador es ${winner}`:null;

    useEffect(() => {
        if (winner != null) {
            ref.current.showModal();
        }
    },[winner]);

    return (<dialog ref={ref} onClose={onOk}><div>
        <h1>{text}</h1>
        <button onClick={onOk}>Restart Game</button></div>
    </dialog>)
};  