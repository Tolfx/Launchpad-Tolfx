import Launchpad from 'launchpad-mini';

export default function Connect(pad: Launchpad)
{
    pad.connect().then(e => {
        console.log(e);
        let btns = Launchpad.Buttons.All;
        pad.col( pad.off, btns );
    });
}