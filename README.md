TUTORIAL:
Vent til animasjonen er ferdig og jorda er i full størrelse. Deretter kan du begynne ved å trykke på "begin". Raketten vil da ta deg med fra jorda ut og til verdensrommet.
Du kan havne i ulike konfigurasjoner ved å klikke deg frem og tilbake, slik at raketten flytter deg dit du skal. Når du får opp en image av stjernen får du litt informasjon om den. 
For å avslutte må man klikke på quit button, men for å finne den må man klikke på end button.

------------------------------------------------------------------------------------------------

I denne filen ligger både dokumentasjonen og refleksjonsnotatene

------------------------------------------------------------------------------------------------
Hva er Stellar?
Stellar er et interaktivt program inspirert av Stellarium, hvor brukeren kan utforske stjerner og verdensrommet gjennom animasjoner og grafikk. Programmet starter med en animasjon av jorda. Når animasjonen er ferdig og jorda er i full størrelse, kan brukeren trykke på begin for å starte. Brukeren blir deretter tatt med ut i verdensrommet med en rakett og kan navigere mellom ulike stjerner og konstellasjoner ved hjelp av knapper. Når en stjerne vises, får man opp et bilde samt informasjon om den. For å avslutte programmet må brukeren først trykke på end-knappen og deretter quit.

------------------------------------------------------------------------------------------------
Dokumentasjon

Utviklingen startet med å kartlegge hvilke klasser og funksjoner vi trengte, samt hvordan disse skulle henge sammen. Vi valgte å bruke objektorientert programmering, der objekter som stjerner og konstellasjoner ble representert som klasser.

For å unngå duplisering av kode laget vi en parent-klasse for objekter med lik funksjonalitet, og brukte arv for å gjenbruke kode. Hver klasse fikk en egen funksjon for å tegne seg selv, som gjorde det enklere å organisere grafikken. I starten var programmet delt opp i flere klasser (runStellar, GridStar, GridConstellation), men dette førte til uoversiktlig kode og vanskelig samhandling mellom komponentene. Derfor valgte vi å samle hovedlogikken i én klasse, Stellar, som arver fra AnimationWindow.

Denne klassen håndterer hele programflyten gjennom funksjonen run(), som inneholder en løkke som kontinuerlig kjører programmet og oppdaterer hva som vises basert på brukerens input. Navigasjon mellom ulike skjermer ble løst ved hjelp av en enum class og en switch-case, som bestemmer hvilke elementer og knapper som skal vises til enhver tid.

For tegninger, brukte vi hovedsakelig bilder som ligger på astrofysikk nettsider slik som NASA og andre atrikler, samt også Wikipedia. Vi brukte et pixel-tegneprogram for å tegne raketten selv.

Her er de viktiste funksjonene:
1. drawBody(): Tegner stjerner og konstellasjoner (override fra parent-klasse)
2. startScreen: Står for animasjoner og oppstart av programmet
3. setFalse(): Styrer hvilke knapper som skal vises
4. callback-funksjoner: Bestemmer hva som skjer når brukeren trykker på knapper
5. run(): Hovedløkken som styrer hele programmet

Ressurser ogverktøy:
1. AnimationsWindow og Widgets
2. Piskelapp.com (for å tegne raketten)
3. Copilot ble brukt for å kopiere det vi allerede har skrevet, og som vi selv skulle kopiere. Dette ble brukt kun i switch-case i run-funksjonen i Stellar klassen.

------------------------------------------------------------------------------------------------
Refleksjonsnotater

Første medlem:
Kan legge til en quit knapp på start screen bare
Her er min tekst. Regner men det kan bli litt overlapp med noe så du for bare slette noe av det:
Utviklingen av Stellar har vært igjennom flere faser med ulik tankegang for å implementere grafikkelementene vi ønsket i programmet. Mye av utviklingen har gått til å finne ut hva som er den beste måten å gå mellom ulike grafikkbilder i AnimationWindow. Vi endte etter flere ulike forsøk på å implementere det i funksjonen Stellar::run(). Vi startetmed å lage klasser for objektene vi ville at skulle vises og ga hver av disse en funksjon for å tegne et bilde av objektet. 

I tillegg fikk objekter som startScreen ekstra funksjonalitet for animasjoner. For å lage konstruktøren til disse objektene ble det brukt filhåndtering for å lett kunne håndtere informasjon og for å gjøre det lettere å lese fra filer ble det implementert operasjonsoverlastninger. Denne måten å bygge opp klassene på med konstruktører og draw-funksjoner la føringen for resten av programmutviklingen For objekter som hadde lik funksjonalitet bIe det for å forenkle prosessen laget en parent-klasse som objektene kunne arve fra. 

I starten var klassen Stellar fordelt i tre ulike klasser som vi kalte runStellar, GridStar og GridConstillation. Dette viste seg derimot å være svart vanskelig å bruke til noe fornuftig i praksis og det ble mye spagettikode for å gå mellom de ulike objektene. For å ungå dette ble all grafikkfunksjonalitet for å gå mellom de ulike sidene implementert i en klasse med navn Stellar, som arver fra AnimationWindow. Denne klassen oppretter et vindu og gjennom funksjonen run håndterer den å gå mellom tegning av de ulike objektene. For å kunne gå tilbake mellom objektene ønsket vi en back-knapp og for å kunne håndtere ulike situasjoner for back-knappen ble det laget en switch-case og en enum class i Stellar som tar hensyn til hvilke kombinasjoner av knapper som skal være synlige på skjermen til hvilken tid, også back-knappen. 

Vi fant ut at det ville være best å bruke gjennomsiktige knapper for må gå mellom de ulike elementene, da man intuitivt kan trykke på dem for å vise objektene. Videre kan det være mulig å implementere funksjonalitet for enda flere stjerner og stjernebilder i fremtiden, noe som bare vil bygge videre på den allerede skrevne koden, slik at man kan utforske en enda større galakse.

Andre medlem:
Utviklingen av Stellar har vært en prosess der det har blitt jobbet med å bygge opp sentrale deler av programstrukturen, spesielt knyttet til implementasjonen av klasser og den tidlige logikken for programflyten. Mye av arbeidet har vært rettet mot å etablere Constellation-klassen og Grid-klassen, som ble brukt til å organisere og håndtere plasseringen av stjerner og konstellasjoner i programmet. For min del ga dette meg en bedre forståelse av hvordan objektorientert programmering kan brukes til å strukturere et større system på en ryddig måte.

Videre ble det jobbet med starten av run()-funksjonen, hovedsakelig logikken bak hvordan programmet skal bevege seg mellom ulike tilstander. Dette innebar å utvikle en forståelse for hvordan programflyten kan styres slik at ulike deler av programmet kobles sammen på en hensiktsmessig måte. Selv om hele run()-funksjonen og startscreen ikke ble utviklet her, ble det lagt et grunnlag for hvordan denne logikken senere kunne bygges videre og ferdigstilles.

Det ble også jobbet med håndtering av bilder i programmet, samt implementasjon av tegning av raketten. Raketten ble brukt som en del av overgangen mellom de ulike delene av programmet, og arbeidet med denne bidro til bedre forståelse av hvordan grafiske elementer kan integreres i programlogikken. I tillegg har det blitt bidratt med debugging og generell støtte i prosjektet der det har vært nødvendig. Dette har vært en viktig del av arbeidet, ettersom feil ofte oppstår i samspillet mellom ulike deler av systemet. Personlig mener jeg at dette arbeidet ble det opparbeidet erfaring med å identifisere og løse feil i både logikk og grafikk, samt forståelsen av viktigheten av testing underveis i utviklingsprosessen.

Konklusjonsvis, gjennom prosjektet har det blitt opparbeidet bedre forståelse for hvordan større programmer bygges opp ved hjelp av klasser, funksjoner og strukturert logikk. Det har også gitt innsikt i hvordan en god struktur tidlig i utviklingen gjør det enklere å videreutvikle programmet, samt hvordan ulike deler av systemet må samarbeide for at helheten skal fungere som tiltenkt.