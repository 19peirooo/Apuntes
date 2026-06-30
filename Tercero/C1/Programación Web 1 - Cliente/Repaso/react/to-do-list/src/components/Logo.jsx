import logoUTAD from "/Logo-U-tad.jpg"
import "./styles/Logo.css"

export default function Logo() {
    return (
        <img src={logoUTAD} alt="Logo UTAD" className="logo"></img>
    );
}