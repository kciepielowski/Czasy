//---------------------------------------------------------------------------

#include <vcl.h>
#include <cstring.h>
#pragma hdrstop

#include "Czasy.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
__int8 Czas1=0;
__int8 Czas2=0;
String slowa[10];
String zd;
String wynik;
void drugaforma();
void trzeciaforma();
__int8 pod, cz;
bool pytanie=false,przeczenie1=false,przeczenie2=false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PastClick(TObject *Sender)
{
  Czas1=0;
  PerfectC->Enabled=true;
  InThePast->Visible=false;
  InThePast->Enabled=false;
  PerfectP->Enabled=false;
  PerfectC->Visible=true;
  if(Czas2==4||Czas2==5)
  {
   Czas2=3;
   InThePast->Checked=false;
   PerfectC->Checked=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PresentClick(TObject *Sender)
{
  Czas1=1;
  PerfectC->Enabled=true;
  InThePast->Visible=false;
  InThePast->Enabled=false;
  PerfectP->Enabled=false;
  PerfectC->Visible=true;
  if(Czas2==4||Czas2==5)
  {
   Czas2=3;
   InThePast->Checked=false;
   PerfectC->Checked=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FutureClick(TObject *Sender)
{
  Czas1=2;
  PerfectC->Enabled=false;
  InThePast->Visible=true;
  InThePast->Enabled=true;
  PerfectP->Enabled=true;
  PerfectC->Visible=false;
  if(Czas2==3)
  {
   Czas2=4;
   InThePast->Checked=true;
   PerfectC->Checked=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SimpleClick(TObject *Sender)
{
  Czas2=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ContinuousClick(TObject *Sender)
{
  Czas2=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PerfectClick(TObject *Sender)
{
  Czas2=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PerfectCClick(TObject *Sender)
{
  Czas2=3;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GenerujClick(TObject *Sender)
{
 pytanie=false;przeczenie1=false;przeczenie2=false;
 wynik="";
 pod=0; cz=1;
 zd=zdanie->Text;
 char z=zd[1];
 unsigned p=1, k=1, i=0, x=1;
 zd+='.';
 while(z!='.'&&z!='?')
 {
 z=zd[x];
  if(z==' '||z=='.'||z=='?')
  {
   slowa[i]=zd.SubString(p,k-p);
   p=k+1;
   i++;
  }
 k++;
 x++;
 }
 if(slowa[0]!=""&&slowa[1]!="")
 {
 int a;
 a=slowa[0].Length();
 for(int i=2;i<=a;i++)
 {
  if(slowa[0][i]<char(91)&&slowa[0][i]>char(64))slowa[0][i]+=32;
 }
 a=slowa[1].Length();
 if(slowa[1]!="I")
 {
 for(int i=1;i<=a;i++)
 {
  if(slowa[1][i]<char(91)&&slowa[1][i]>char(64))slowa[1][i]+=32;
 }
 }
 for(int j=2;;j++)
 {
 if(slowa[j]!="")
 {
 a=slowa[j].Length();
 for(int i=1;i<=a;i++)
 {
  if(slowa[j][i]<char(91)&&slowa[j][i]>char(64))slowa[j][i]+=32;
 }
 }else break;
 }
 if(slowa[0]=="Do"||slowa[0]=="do"||slowa[0]=="Does"||slowa[0]=="does")
 {
  pod=1; cz=2;
  pytanie=true;
 }
 if(slowa[2]=="not")
 {
 cz=3;
 przeczenie1=true;
 //przeczenie z not
 }
 if(slowa[1]=="don't"||slowa[1]=="dont"||slowa[1]=="doesn't"||slowa[1]=="doesnt")
 {
  cz=2;
  przeczenie2=true;
 //przeczenie z n't
 }
 if(pod==0)
 {
  a=slowa[cz].Length();
  wynik+=slowa[0]+' ';
  if(slowa[0]=="He" || slowa[0]=="he" || slowa[0]=="She"
  || slowa[0]=="she" || slowa[0]=="It" || slowa[0]=="it")
  {
   if(slowa[cz]!="is")
   {
    if(slowa[cz][a]=='s'&&slowa[cz][a-1]=='e')
    {
    slowa[cz]=slowa[cz].SubString(0, a-1);
    --a;
    bool znaleziono=false;
     String czasownik[2026]={"abase", "abate", "abbreviate", "abdicate",
 "aberrate", "abide", "abjure", "ablate", "abnegate", "abrade", "abridge",
 "abrogate", "abscise", "absolve",  "abuse", "accede", "accelerate",
 "accentuate", "acclimate", "acclimatise","acclimatise", "accommodate",
 "accrue", "accumulate", "accuse", "acetylate", "ache", "achieve",
 "achromatize", "acidulate", "acknowledge", "acquaint", "acquiesce",
 "acquire", "activate", "actualise", "actuate", "adhere", "adjudicate",
 "adjure", "admire", "adore", "adulate", "adulterate", "adumbrate", "advance",
 "advertise", "advise", "advocate", "aerate", "affiliate", "africanise", "age",
 "agglomerate", "agglutinate", "aggrandize", "aggravate", "aggregate", "agitate", "aglomerate", "agonize", "agree", "alcholise", "alcoholise", "alert",
 "alienate", "aline", "alkalinise", "alkalise", "alkylate", "allege", "allegorise",
 "allergise", "alleviate", "allocate","allude", "allure","alternate", "amalgamate",
 "amaze", "amble", "ambulate", "ameliorate", "amerce", "americanise", "ammoniate",
 "amortise","amputate", "amuse", "anaesthetise", "analyse", "anastomose",
 "anathematise", "angle", "anglicise", "animalise", "animate", "annihilate",
 "annotate", "announce", "annunciate", "anoxiate", "antagonise", "antedate",
 "anthropomorphise", "anticipate", "anticoagulate", "antisepticise", "ape", "apologise",
 "apostrophise", "appease", "appraise", "appreciate", "appropriate", "approve",
 "approximate", "arbitrate", "argue", "arise", "armour-plate", "arouse", "arrange",
 "arrive", "arterialise", "articulate", "ascribe", "asperse", "asphyxiate", "aspirate",
 "aspire", "assassinate", "assemble", "asseverate", "assimilate", "associate",
 "assuage", "assume", "assure", "atomise", "atone", "attenuate", "attribute",
 "auscultate", "authenticate", "authorise", "authorise", "autolyse", "automate",
 "avenge", "average", "avianise", "awake", "axotomise", "babble", "back-fire",
 "backslide", "baffle", "balance", "bale", "bamboozle", "bandage", "baptise",
 "bare", "barricade", "base", "baste", "bathe", "battle", "be", "become",
 "beguile", "behave", "believe", "belittle", "bemuse", "bereave", "besiege",
 "bespangle", "bifurcate", "biodegrade", "bite", "blame", "blaze", "bone",
 "booze", "bore", "botanise", "bottle", "bounce", "brake", "brave", "breathe",
 "bribe", "bridle", "bristle", "brocade",
 "brominate", "bronze", "browse", "bruise", "brutalise", "bubble", "buckle",
 "bulge", "bundle", "bungle", "burglarise", "burgle", "cable", "cackle",
 "cadge", "cage", "cajole", "calculate", "calibrate", "calve", "camouflage",
 "canalize", "cane", "cannibalise", "cannonade", "cannulate", "canonise",
 "capitalise", "capitulate", "caponise", "capsise", "captivate", "capture",
 "carbonate", "carbonise", "care", "caricature", "caricuture", "carve",
 "cascade", "case", "castigate", "castrate", "catabolise", "catalyse",
"categorise", "catheterise", "cause", "causticise", "cauterise", "cavitate",
 "cease", "celebrate", "censure", "centralise", "centre", "centuplicate",
 "challenge", "chance", "change", "chaperone", "characterise", "charge",
 "chase", "chastise", "chelate", "chide", "chime", "chlorinate", "choke",
 "choose", "christianise", "chuckle", "circulate", "circumcise",
 "circumnavigate", "circumscribe", "cite", "civilise", "cleanse", "cleave",
 "close", "clothe", "co-operate", "co-ordinate", "coagulate", "coalesce",
 "coarctate", "cocainise", "cocultivate", "coddle", "code", "coerce",
 "cogitate", "cohere", "coincide", "collaborate", "collapse", "collate",
 "collectivise", "collide", "collocate", "collude", "colonise", "combine",
 "come", "commemorate", "commence", "commercialise", "commiserate",
 "communicate", "commute", "compare", "compartmentalise", "compensate",
 "compete", "compile", "complete", "complicate", "compose", "compromise",
 "compute", "computerise", "concatenate", "concede", "conceive", "concentrate",
 "conceptualise", "conciliate", "conclude", "concrete", "condense", "condole",
 "conduce", "confabulate", "confederate", "confide", "configure", "confine",
 "confiscate", "confuse", "confute", "conglomerate", "conglutinate",
 "congratulate", "congregate", "conjecture", "conjugate", "conjure", "connote",
 "consecrate", "consecrate", "conserve", "console", "consolidate", "conspire",
 "consternate", "constipate", "constitute", "constitutionalise", "consume",
 "consummate", "contaminate", "contemplate", "continue", "contraindicate",
 "contravene", "contribute", "contrive", "contuse", "convalesce", "convene",
 "converge", "converse", "convince", "convulse", "cooperate", "coordinate",
 "copperplate", "copulate", "correlate", "corroborate", "corrode", "corrugate",
 "coruscate", "counter-balance", "counterbalance", "couple", "crackle", "crave",
"crease", "create", "cremate", "crenelate", "crepitate", "criminalise",
 "cringe", "crinkle", "cripple", "criticise", "cross-fertilise", "cross-rule",
 "crumble", "crumple", "crusade", "crystallise", "cube", "cuddle", "culminate",
 "cultivate", "curdle", "cure", "curette", "curse", "curve", "dabble", "damage",
 "damascene", "dance", "dandle", "dangle", "dare", "date", "dawdle", "dazzle",
 "deafferentate", "deamidate", "deamidise", "deaminate", "debase", "debate",
 "debilitate", "debride", "decapitate", "decarboxylate", "decease", "deceive",
 "decelerate", "decentralise", "decerebrate", "dechlorinate", "dechristianise",
 "decide", "decimate", "declare", "decline", "decode", "decolonise",
 "decolourise", "decompensate", "decompose", "decontaminate", "decorate",
 "decrease", "decree", "decrepitate", "decussate", "dedicate",
 "dedifferentiate", "deduce", "deface", "defame", "defecate", "defibrillate",
 "defile", "define", "deflate", "defoliate", "defreeze", "degenerate",
 "deglycosylate", "degrade", "degranulate", "dehalogenate", "dehisce",
 "dehumanise", "dehydrate", "dehydrogenate", "deinduce", "deinstitutionalise",
 "deionise", "delegate", "delete", "deliberate", "delimitate", "delineate",
 "deliquesce", "delocalise", "delouse", "delude", "delve", "demagnetise",
 "demarcate", "dematerialise", "demetalise", "demethylate", "demilitarise",
 "demineralise", "demobilise", "democratise", "demonetise", "demonstrate",
 "demoralise", "demote", "demyelinate", "denationalise", "denature",
 "denervate", "denigrate", "denominate", "denote", "denouce", "denounce",
 "denude", "deoxidise", "depersonalise", "dephosphorylate", "depilate",
 "deplete", "deplore", "depolarise", "depolymerise", "depopulate", "depose",
 "deprave", "deprecate", "depreciate", "deprive", "depurate", "derange",
 "deregulate", "deride", "derive", "derogate", "desalinate", "desamidate",
 "desamidise", "desaturate", "describe", "desecrate", "desegregate",
 "desensitise", "deserve", "desexualise", "designate", "desire", "desolate",
 "despeciate", "destabilise", "deteriorate", "determine", "dethrone",
 "detonate", "detoxicate", "deuterate", "devaluate", "devalue", "devastate",
 "deviate", "devise", "devitalise", "devolve", "devote", "dextrinate",
 "dextrinise", "diagnose", "dialyse", "dialyze", "diazotise", "dicatate",
 "dichotomise", "dictate", "die", "differentiate", "diffuse", "dilapidate",
 "dilate", "dilute", "dine", "disable", "disabuse", "disagree", "disapprove",
 "disarrange", "disbelieve", "disburse", "discharge", "discipline", "disclose",
 "discompose", "discontinue", "discourage", "discourse", "discriminate",
 "disengage", "disentagle", "disentangle", "disfigure", "disgorge", "disgrace",
 "disguise", "disincline", "disintegrate", "dislocate", "dislodge", "dismantle",
 "disolve", "disorganise", "disorientate", "disparage", "dispense", "disperse",
 "displace", "displease", "dispose", "disprove", "dispute", "disseminate",
 "dissimilate", "dissimulate", "dissipate", "dissociate", "dissolve",
 "dissuade", "distribute", "disunite", "divagate", "dive", "diverge", "divide",
 "divine", "divorce", "divulge", "divulse", "dodge", "dogmatise", "domesticate",
 "dominate", "donate", "dope", "dote", "double", "doze", "dramatise", "drape",
 "dredge", "dribble", "drive", "drizzle", "drowse", "dupe", "duplicate", "dye",
 "eclipse", "economise", "ecphorise", "edge", "educate", "efface", "effervesce",
 "ejaculate", "elaborate", "electrocute", "elevate", "eliminate", "elongate",
 "elope", "elucidate", "elude", "elute", "emaciate", "emanate", "emancipate",
 "emasculate", "embezzle", "embolise", "embrace", "embrocate", "emerge",
 "emigrate", "emphasise", "emulate", "enable", "encircle", "enclose",
 "encourage", "endorse", "endure", "energise", "enervate", "enfeeble",
 "enforce", "enfranchise", "engrave", "enhance", "enlarge", "ennoble",
 "enquire", "enrage", "enrapture", "enshrine", "enslave", "ensnare", "ensue",
 "entangle", "enthrone", "enthuse", "entice", "entitle", "entwine", "enucleate",
 "enumerate", "enunciate", "epilate", "epitomise", "equalise", "equate",
 "equivocate", "eradicate", "erase", "erode", "erotise", "escalate", "escape",
 "espouse", "estimate", "estrange", "eulogise", "Eurpeanise", "evacuate",
 "evade", "evaluate", "evaporate", "evidence", "eviscerate", "evoke", "evolve",
 "exacerbate", "exaggerate", "examine", "exasperate", "excavate", "exchange",
 "excise", "excite", "exclude", "excogitate", "excommunicate", "excoriate",
 "excrete", "exculpate", "excuse", "execrate", "execute", "exercise",
 "exfoliate", "exhale", "exhilarate", "exhume", "exile", "exonerate",
 "exorcise", "expatriate", "expectorate", "expedite", "experience", "expiate",
 "expire", "explicate", "explode", "explore", "expose", "expostulate",
 "expropriate", "expurgate", "exsanguinate", "extenuate", "exteriorise",
 "exterminate", "externalise", "extirpate", "extradite", "extrapolate",
 "extricate", "extrude", "exude", "eye", "fabricate", "face", "facilitate",
 "factorise", "fade", "fake", "familiarise", "fascinate", "fecundate",
 "federate", "feminise", "fence", "fenestrate", "fertilise", "fibrillate",
 "fiddle", "file", "filtrate", "finance", "fire", "fissure", "fixate",
 "flagellate", "flake", "flame", "flare", "flee", "fleece", "flounce",
 "fluctuate", "fluoresce", "fluoridate", "fluoridise", "flute", "fondle",
 "forbode", "force", "forebode", "foreclose", "foresee", "forge", "forgive",
 "formalise", "formulate", "fornicate", "forsake", "fossilise", "fracture",
 "frame", "fraternise", "free", "freelance", "freeze", "fricassee", "fringe",
 "frustrate", "fulminate", "fumble", "fume", "fumigate", "fungate", "fuse",
 "galvanise", "gamble", "gangrene", "gape", "garotte", "gauge", "gelate",
 "gelatinise", "generalise", "generate", "germinate", "gesticulate", "give",
 "glamorise", "glare", "glaze", "glimpse", "globalise", "glove", "gobble",
 "gouge", "grade", "graduate", "granulate", "grate", "gravitate", "graze",
 "grease", "grieve", "grimace", "groove", "grope", "grouse", "grumble",
 "guarantee", "guide", "guillotine", "gurgle", "guzzle", "gyrate",
 "haemorrhage", "haggle", "hallucinate", "halogenate", "handle", "harangue",
 "harmonise", "hassle", "hate", "have", "heave", "Hellenise", "herniate",
 "hesitate", "hibernate", "hide", "hinge", "hire", "hobble", "hoe",
 "homogenise", "hope", "hospitalise", "huddle", "humanise", "humble",
 "humiliate", "hybridise", "hydrate", "hyperventilate", "hyphenate",
 "hypnotise", "hypostasise", "ice", "idealise", "idle", "idolise", "ignite",
 "ignore", "illuminate", "illustrate", "imagine", "imitate", "immaterialise",
 "immerge", "immigrate", "immobilise", "immolate", "immortalise", "immunise",
 "immure", "impale", "impersonate", "implicate", "implode", "implore", "impose",
 "imprecate", "impregnate", "improve", "improvise", "impute", "inactivate",
 "inaugurate", "incapacitate", "incarcerate", "incarnate", "incense",
 "incinerate", "incise", "incite", "incline", "inclose", "include",
 "inconvenience", "incorporate", "increase", "incriminate", "incubate",
 "inculcate", "indicate", "individualise", "indoctrinate", "indorse", "induce",
 "indulge", "indurate", "industrialise", "inebriate", "infiltrate", "inflame",
 "inflate", "influence", "infringe", "infuriate", "infuse", "inhale",
 "initiate", "injure", "innervate", "innovate", "inoculate", "inosculate",
 "inquire", "inscribe", "insensibilise", "insinuate", "inspire", "instigate",
 "institute", "institutionalise", "insulate", "insure", "integrate",
 "intellectualise", "intercalate", "intercede", "intercommunicate",
 "interdigitate", "interface", "interfere", "interlace", "intermingle",
 "internalise", "internationalise", "interpellate", "interpolate", "interpose",
 "interrelate", "interrogate", "intertwine", "intervene", "interweave",
 "intimate", "intimidate", "intone", "intoxicate", "intrigue", "introduce",
 "intrude", "intubate", "intumesce", "inundate", "invade", "invaginate",
 "invalidate", "inverse", "investigate", "invigilate", "invigorate", "invite",
 "invoke", "involve", "iodise", "ionise", "irradiate", "irrigate", "irritate",
 "isolate", "issue", "itemise", "iterate", "jeopardise", "jibe", "jingle",
 "joke", "jostle", "jubilate", "judge", "juggle", "jumble", "juxtapose",
 "keratinise", "kindle", "lace", "lacerate", "laminate", "lapinise", "latinise",
 "lease", "leave", "lecture", "legalise", "legislate", "legitimate", "levitate",
 "liaise", "liberalise", "liberate", "licence", "license", "lie", "ligate",
 "like", "lime", "line", "linearise", "lionise", "liquidate", "litigate",
 "live", "loathe", "localise", "locate", "lodge", "lose", "love", "lubricate",
 "lunge", "lure", "lute", "lyophilise", "macadamise", "macerate", "magnetise",
 "make", "manage", "mangle", "manhandle", "manipulate", "manufacture",
 "marinate", "masculinise", "mass-produce", "massacre", "massage", "masticate",
 "masturbate", "materialise", "matriculate", "maturate", "mature", "maximise",
 "measure", "mechanise", "mediatise", "medicate", "meditate", "meliorate",
 "memorialise", "memorise", "menace", "menstruate", "merge", "mesmerise",
 "metabolise", "metamorphisise", "micronise", "migrate", "militarise", "mime",
 "mince", "mine", "mineralise", "miniaturise", "minimise", "misappropriate",
 "misbehave", "miscalculate", "misconceive", "misconstrue", "misdiagnose",
 "misfire", "misjudge", "mismanage", "misplace", "mispronounce", "misquote",
 "misshape", "misstate", "mistake", "mistranslate", "misuse", "mitigate",
 "mobilise", "moderate", "modernise", "modulate", "mollycoddle", "monologue",
 "monopolise", "moralise", "mortgage", "mortise", "motivate", "motorise",
 "mottle", "move", "muddle", "muffle", "mumble", "muse", "mutate", "mute",
 "mutilate", "muzzle", "name", "narcotise", "narrate", "nasalise",
 "nationalise", "naturalise", "nauseate", "navigate", "nebulise", "necessitate",
 "negate", "negotiate", "nestle", "neutralise", "nibble", "nickname",
 "nomadise", "nominate", "normalise", "nose", "note", "notice", "nurse",
 "obfuscate", "objurgate", "obligate", "oblige", "obliterate", "obscure",
 "observe", "obtrude", "occlude", "occlure", "officiate", "ogle", "ooze",
 "operate", "oppose", "opsonise", "optimise", "orate", "orchestrate",
 "organise", "orientate", "originate", "oscillate", "oscitate", "osmicate",
 "osmose", "ostracise", "outdistance", "outline", "outrage", "outshine",
 "overcapitalise", "overcome", "overemphasise", "overestimate", "overexcite",
 "overexpose", "overindulge", "overproduce", "oversaturate", "oversee",
 "overstate", "overtake", "overvalue", "owe", "oxidise", "oxygenate", "ozonise",
 "pace", "paddle", "pale", "palliate", "palpate", "palpitate", "parachute",
 "parade", "paralyse", "paraphrase", "parasitise", "pare", "participate",
 "particularise", "passivise", "paste", "pasteurise", "pasture", "patronise",
 "pauperise", "pause", "pave", "peculate", "peddle", "pee", "pellate",
 "penalise", "penetrate", "people", "perambulate", "perceive", "percolate",
 "peregrinate", "perforate", "perfuse", "permeate", "permute", "perpetrate",
 "perpetuate", "persecute", "persevere", "personalise", "perspire", "persuade",
 "peruse", "pervade", "philosophise", "phone", "phosphorate", "photoactivate",
 "photosensitise", "phrase", "picture", "pierce", "pile", "pillage", "pique",
 "pirate", "pirouette", "place", "plagiarise", "plane", "plate", "please",
 "plunge", "poke", "polarise", "politicise", "pollinate", "pollute",
 "polymerise", "pommade", "pontificate", "popularise", "populate", "pose",
 "postdate", "postpone", "postulate", "potentiate", "practice", "practise",
 "praise", "prattle", "prearrange", "precede", "precipitate", "preclude",
 "preconceive", "predestinate", "predestine", "predetermine", "predispose",
 "predominate", "prefabricate", "preincubate", "prejudge", "prelude",
 "premeditate", "prepare", "preponderate", "prescribe", "preserve", "preside",
 "presume", "presuppose", "prevaricate", "privilege", "prize", "probe",
 "procrastinate", "procreate", "procure", "produce", "profane",
 "professionalise", "profile", "prognose", "prognosticate", "prolapse",
 "proletarianise", "proliferate", "promise", "promote", "promulgate", "pronate",
 "pronounce", "propagate", "propitiate", "propogate", "propose", "propulse",
 "proscribe", "prosecute", "proselytise", "prostitute", "protrude", "prove",
 "provide", "provoke", "prune", "psychoanalyse", "puke", "pullulate", "pulsate",
 "pulverise", "punctuate", "puncture", "purchase", "pure", "purge", "pursue",
 "puzzle", "quadruple", "quibble", "quintuple", "quote", "radiate",
 "radicalise", "rage", "raise", "rake", "ramble", "randomise", "rape",
 "rationalise", "rattle", "ravage", "rave", "re-assemble", "re-cane", "re-dye",
 "re-educate", "re-emerge", "re-engage", "re-shape", "reacquire", "reactivate",
 "realise", "rearrange", "reassemble", "reassure", "rebaptise", "rebuke",
 "recapitulate", "recapture", "recede", "receive", "recharge", "rechristianise",
 "reciprocate", "recite", "recognise", "recombine", "recommence",
 "recompensate", "recompose", "reconcile", "reconnoitre", "reconsolidate",
 "reconstitute", "recreate", "recriminate", "recuperate", "redimise",
 "redistribute", "redouble", "reduce", "reduplicate", "reevaluate", "reexamine",
 "refine", "reflate", "reformulate", "refrigerate", "refuse", "refute",
 "regale", "regenerate", "regularise", "regulate", "regurgitate",
 "rehabilitate", "rehearse", "rehouse", "reimburse", "reimpose", "reincarnate",
 "reincorporate", "reinflate", "reinforce", "reinstate", "reinsure",
 "reintegrate", "reintroduce", "reinvigorate", "reiterate", "rejoice",
 "rejuvenate", "rekindle", "relapse", "relate", "release", "relegate",
 "relieve", "relocate", "remilitarise", "reminisce", "remonstrate", "remove",
 "remunerate", "rename", "renounce", "renovate", "reoperate", "reorchestrate",
 "reorganise", "reorientate", "repatriate", "repave", "replace", "replicate",
 "repopulate", "reprobate", "reproduce", "reprove", "republicanise",
 "repudiate", "repute", "require", "rescue", "resemble", "reserve", "reshape",
 "reshuffle", "reside", "resinate", "resole", "resolve", "resource", "respire",
 "restate", "restore", "resume", "resuscitate", "resuscitate", "resynthesise",
 "retaliate", "retie", "retire", "retrace", "retranslate", "retrieve",
 "retrograde", "reunite", "revalue", "reverberate", "revere", "reverse",
 "revile", "revise", "revitalise", "revive", "revoke", "revolutionise",
 "revolve", "reweave", "rhapsodise", "rhyme", "ride", "ridge", "ridicule",
 "rifle", "rinse", "ripple", "rise", "roller-skate", "romanise", "rope",
 "rotate", "rouge", "rough-plane", "rouse", "rove", "rubberise", "ruffle",
 "rule", "rumble", "ruminate", "rummage", "rupture", "rusticate", "rustle",
 "sabotage", "sacrifice", "saddle", "salivate", "salute", "salvage", "sample",
 "sanitise", "satiate", "satinise", "satirise", "saturate", "savage", "save",
 "scale", "scandalise", "scare", "schematise", "scheme", "scintillate",
 "sclerose", "score", "scrape", "scribble", "scrounge", "scrutanise",
 "scrutinise", "scuffle", "scuttle", "secede", "seclude", "secrete",
 "secularise", "secure", "sedate", "seduce", "see", "segregate", "seize",
 "sense", "sensitise", "sensualise", "sentence", "sentimentalise", "separate",
 "sequestrate", "serialise", "serve", "settle", "shade", "shake", "shape",
 "share", "shave", "sheathe", "sheave", "shine", "shoe", "shore", "shuffle",
 "sickle", "side", "sieve", "silhouette", "simulate", "singe", "single",
 "singularise", "site", "situate", "sizzle", "skate", "skedaddle", "slave",
 "slice", "slide", "smile", "smoke", "sneeze", "snipe", "snooze", "snore",
 "socialise", "sodomise", "sol-fa", "solace", "solemnise", "solidarise",
 "solve", "somatise", "sonicate", "soothe", "sophisticate", "souse",
 "sovietise", "space", "spangle", "sparkle", "spatialise", "spatulate",
 "specialise", "speckle", "speculate", "spice", "spiritualise", "sponge",
 "sprinkle", "spruce", "squabble", "square", "squeeze", "stabilise", "stable",
 "stagnate", "stake", "standardise", "staple", "stare", "starve", "state",
 "stave", "stereotype", "sterilise", "sterotype", "stigmatise", "stimulate",
 "stipulate", "stone", "store", "straddle", "strangle", "streamline", "strike",
 "stripe", "strive", "structure", "struggle", "stumble", "style", "stylise",
 "subcultivate", "subdivide", "subdue", "subjugate", "sublimate", "submerge",
 "subordinate", "subrogate", "subscribe", "subside", "subsidise",
 "substantiate", "substitute", "subtilise", "suckle", "sue", "suffice",
 "suffocate", "suffuse", "sulphate", "sulphurise", "summarise", "superannuate",
 "supercede", "superimpose", "superinduce", "superpose", "supersaturate",
 "superscribe", "supersede", "supervise", "supinate", "supplicate", "suppose",
 "suppurate", "surge", "surprise", "survive", "suture", "swaddle", "swindle",
 "symbolise", "sympathise", "synchronise", "syndicate", "synthesise", "syringe",
 "systematise", "tabulate", "take", "tame", "tangle", "taste", "tease",
 "telephone", "televise", "temporise", "terminate", "terrorise", "tetanise",
 "theorise", "thrive", "throttle", "tickle", "tie", "tierce", "tile", "time",
 "tin-plate", "tinge", "tinkle", "tipple", "tire", "titilate", "titillate",
 "titivate", "toe", "tolerate", "tone", "tonsure", "topple", "torture",
 "tousle", "trace", "trade", "trample", "tranquilise", "transcribe",
 "transduce", "transfigure", "transfuse", "transilluminate", "translate",
 "transliterate", "translocate", "transmigrate", "transmute", "transpire",
 "transpose", "transubtantiate", "transude", "treasure", "treble", "tremble",
 "triangulate", "trickle", "trifle", "triple", "triplicate", "tritiate",
 "triturate", "trouble", "truncate", "tube", "tumble", "tune", "tussle",
 "twiddle", "twinkle", "type", "tyrannise", "ulcerate", "unalienate",
 "unbalance", "unbandage", "unbridle", "unbuckle", "uncouple", "undeceive",
 "underestimate", "underexpose", "underline", "undermine", "understate",
 "undertake", "undervalue", "undulate", "unhinge", "unionise", "unite",
 "universalise", "unlace", "unmuzzle", "unpave", "unprime", "unsaddle",
 "unshackle", "unswaddle", "untangle", "untie", "upbrade", "update", "urbanise",
 "urge", "urinate", "use", "utilise", "vacate", "vaccinate", "vacillate",
 "vacuolate", "validate", "value", "vaporise", "variegate", "variolate",
 "vascularise", "vaticinate", "vegetate", "venerate", "ventilate", "venture",
 "vibrate", "victimise", "vindicate", "violate", "visualise", "vitiate",
 "vitriolise", "vituperate", "vocalise", "vocalise", "vociferate", "volitalise",
 "volitilise", "vote", "vouchsafe", "vulcanise", "vulgarise", "wage", "wake",
 "wangle", "warble", "waste", "wave", "weave", "wedge", "welcome", "westernise",
 "wheedle", "whine", "whistle", "wince", "wipe", "wire", "wobble", "wrangle",
 "wrestle", "wriggle", "wrinkle", "write"};
     for(int i=0; i<2026;i++)
     {
      if(czasownik[i]==slowa[cz]){znaleziono=true; break;}
     }
     if(!znaleziono){slowa[cz]=slowa[cz].SubString(0, a-1); --a;}
    }
   }
  }
 }
  if(Czas1==1 && Czas2==0) //present simple
 {
  if(pytanie)wynik+=slowa[0]+' '+slowa[1]+' ';
  if(przeczenie1)wynik+=slowa[1]+' '+slowa[2]+' ';
  if(przeczenie2)wynik+=slowa[1]+' ';
  if(slowa[0]=="He" || slowa[0]=="he" || slowa[0]=="She"
  || slowa[0]=="she" || slowa[0]=="It" || slowa[0]=="it")
  {
   if(slowa[1]!="is"&&slowa[1]!="has"&&cz==1){if(slowa[1][a]=='e'){slowa[1]+='s';}else slowa[1]+="es";}
  }
 }
 if(Czas1==0 && Czas2==0) //past simple
 {
  if(pytanie){
  if(slowa[cz]=="has")slowa[cz]="had";
  wynik+="Did "+slowa[1]+' ';}
  if(przeczenie1){
  if(slowa[cz]=="has")slowa[cz]="had";
  wynik+="did not ";}
  if(przeczenie2){
  if(slowa[cz]=="has")slowa[cz]="had";
  wynik+="didn't ";}
  if(cz==1)drugaforma();
 }
 if(Czas1==0 && Czas2==1) //past continuous
 {
  if(slowa[pod]=="I" || slowa[pod]=="i" || slowa[pod]=="He"
   || slowa[pod]=="he" || slowa[pod]=="She" || slowa[pod]=="she"
   || slowa[pod]=="It" || slowa[pod]=="it")
   {
    if(cz==1)wynik+="was ";
    if(przeczenie1)wynik+="was not ";
    if(przeczenie2)wynik+="wasn't ";
    if(pytanie)wynik+="Was "+slowa[1]+' ';
   }else
   {
    if(cz==1)wynik+="were ";
    if(przeczenie1)wynik+="were not ";
    if(przeczenie2)wynik+="weren't ";
    if(pytanie)wynik+="Were "+slowa[1]+' ';
   }
 }
 if(Czas1==0 && Czas2==2) //past perfect
 {
  if(cz==1)wynik+="had ";
  if(przeczenie1)wynik+="had not ";
  if(przeczenie2)wynik+="hadn't ";
  if(pytanie)wynik+="Had "+slowa[1]+' ';
  trzeciaforma();
 }
 if(Czas1==0 && Czas2==3) //past perfect continuous
 {
  if(cz==1)wynik+="had ";
  if(przeczenie1)wynik+="had not ";
  if(przeczenie2)wynik+="hadn't ";
  if(pytanie)wynik+="Had "+slowa[1]+' ';
 }
 if(Czas1==1 && Czas2==1) //present continuous
 {
  if(slowa[pod]=="I" || slowa[pod]=="i")
  {
   if(cz==1)wynik+="am ";
   if(pytanie)wynik+="Am "+slowa[1]+' ';
   if(przeczenie1||przeczenie2)wynik+="am not ";
  }
  if(slowa[pod]=="He" || slowa[pod]=="he" || slowa[pod]=="She"
  || slowa[pod]=="she" || slowa[pod]=="It" || slowa[pod]=="it")
  {
   if(cz==1)wynik+="is ";
   if(pytanie)wynik+="Is "+slowa[1]+' ';
   if(przeczenie1)wynik+="is not ";
   if(przeczenie2)wynik+="isn't ";
  }
  if(slowa[pod]=="You" || slowa[pod]=="you" || slowa[pod]=="We" || slowa[pod]=="we"
  || slowa[pod]=="They" || slowa[pod]=="they" || slowa[pod]=="Those"
  || slowa[pod]=="those")
  {
   if(cz==1)wynik+="are ";
   if(pytanie)wynik+="Are "+slowa[1]+' ';
   if(przeczenie1)wynik+="are not ";
   if(przeczenie2)wynik+="aren't ";
  }
 }
 if(Czas1==1 && Czas2==2) //present perfect
 {
  if(slowa[pod]=="He" || slowa[pod]=="he" || slowa[pod]=="She"
   || slowa[pod]=="she" ||slowa[pod]=="It" || slowa[pod]=="it")
   {
    if(cz==1)wynik+="has ";
    if(pytanie)wynik+="Has "+slowa[1]+' ';
    if(przeczenie1)wynik+="has not ";
    if(przeczenie2)wynik+="hasn't ";
   }else
   {
    if(cz==1)wynik+="have ";
    if(pytanie)wynik+="Have "+slowa[1]+' ';
    if(przeczenie1)wynik+="have not ";
    if(przeczenie2)wynik+="haven't ";
   }
   trzeciaforma();
 }
 if(Czas1==1 && Czas2==3) //present perfect continuous
 {
  if(slowa[pod]=="He" || slowa[pod]=="he" || slowa[pod]=="She"
   || slowa[pod]=="she" ||slowa[pod]=="It" || slowa[pod]=="it")
   {
    if(cz==1)wynik+="has ";
    if(pytanie)wynik+="Has "+slowa[1]+' ';
    if(przeczenie1)wynik+="has not ";
    if(przeczenie2)wynik+="hasn't ";
   }else
   {
    if(cz==1)wynik+="have ";
    if(pytanie)wynik+="Have "+slowa[1]+' ';
    if(przeczenie1)wynik+="have not ";
    if(przeczenie2)wynik+="haven't ";
   }
 }
 if(Czas1==2 && Czas2==0) //future simple
 {
  if(slowa[cz]=="am"||slowa[cz]=="are"||slowa[cz]=="is")slowa[cz]="be";
  if(slowa[cz]=="has")slowa[cz]="have";
  if(slowa[pod]=="I" || slowa[pod]=="i" || slowa[pod]=="We" || slowa[pod]=="we")
  {
   if(cz==1)wynik+="shall ";
   if(pytanie)wynik+="Shall "+slowa[1]+' ';
   if(przeczenie1||przeczenie2)wynik+="shall not ";
  }else
  {
   if(cz==1)wynik+="will ";
   if(pytanie)wynik+="Will "+slowa[1]+' ';
   if(przeczenie1||przeczenie2)wynik+="will not ";
  }
 }
 if(Czas1==2 && Czas2==1) //future continuous
 {
  if(slowa[pod]=="I" || slowa[pod]=="i" || slowa[pod]=="We" || slowa[pod]=="we")
  {
   if(cz==1)wynik+="shall be ";
   if(pytanie)wynik+="Shall "+slowa[1]+" be ";
   if(przeczenie1||przeczenie2)wynik+="shall not be ";
  }else
  {
   if(cz==1)wynik+="will be ";
   if(pytanie)wynik+="Will "+slowa[1]+" be ";
   if(przeczenie1||przeczenie2)wynik+="will not be ";
  }
 }
 if(Czas1==2 && Czas2==2) //future perfect
 {
  if(slowa[pod]=="I" || slowa[pod]=="i" || slowa[pod]=="We" || slowa[pod]=="we")
  {
   if(cz==1)wynik+="shall have ";
   if(pytanie)wynik+="Shall "+slowa[1]+" have ";
   if(przeczenie1||przeczenie2)wynik+="shall not have ";
  }else
  {
   if(cz==1)wynik+="will have ";
   if(pytanie)wynik+="Will "+slowa[1]+" have ";
   if(przeczenie1||przeczenie2)wynik+="will not have ";
  }
  trzeciaforma();
 }
 if(Czas1==2 && Czas2==4) //future in the past
 {
  if(slowa[cz]=="am"||slowa[cz]=="are"||slowa[cz]=="is")slowa[cz]="be";
  if(slowa[cz]=="has")slowa[cz]="have";
  if(slowa[pod]=="I" || slowa[pod]=="i" || slowa[pod]=="We" || slowa[pod]=="we")
  {
   if(cz==1)wynik+="should ";
   if(pytanie)wynik+="Should "+slowa[1]+' ';
   if(przeczenie1)wynik+="should not ";
   if(przeczenie2)wynik+="shouldn't ";
  }else
  {
   if(cz==1)wynik+="would ";
   if(pytanie)wynik+="Would "+slowa[1]+' ';
   if(przeczenie1)wynik+="would not ";
   if(przeczenie2)wynik+="wouldn't ";
  }
 }
  if(Czas1==2 && Czas2==5) //future perfect in the past
 {
  if(slowa[pod]=="I" || slowa[pod]=="i" || slowa[pod]=="We" || slowa[pod]=="we")
  {
   if(cz==1)wynik+="should have ";
   if(pytanie)wynik+="Should "+slowa[1]+" have ";
   if(przeczenie1)wynik+="should not have ";
   if(przeczenie2)wynik+="shouldn't have ";
  }else
  {
   if(cz==1)wynik+="would have ";
   if(pytanie)wynik+="Would "+slowa[1]+" have ";
   if(przeczenie1)wynik+="would not have ";
   if(przeczenie2)wynik+="wouldn't have ";
  }
  trzeciaforma();
 }
 if(Czas2==1 || Czas2==3) //continuous ("-ing")
 {
  if(slowa[cz]=="am"||slowa[cz]=="are"||slowa[cz]=="is")slowa[cz]="be";
  if(slowa[cz]=="has")slowa[cz]="have";
  int b=0;  // a,
  a=slowa[cz].Length();
 for(int i=1; i<a; i++)
 {
  if(slowa[cz][i]=='a'||slowa[cz][i]=='i'||slowa[cz][i]=='o'||
  slowa[cz][i]=='u'||slowa[cz][i]=='y'||slowa[cz][i]=='e')b++;
 }
  if(b==1)
  {
   if(slowa[cz][a]!='x'&&slowa[cz][a]!='w'&&slowa[cz][a]!='z'&&slowa[cz][a]!='a'
   &&slowa[cz][a]!='i'&&slowa[cz][a]!='o'&&slowa[cz][a]!='u'&&slowa[cz][a]!='u'
   &&slowa[cz][a]!='e'&&slowa[cz][a]!='y')
   {
   if(slowa[cz][a-1]=='i'||slowa[cz][a-1]=='o'||slowa[cz][a-1]=='u'
   ||slowa[cz][a-1]=='e')slowa[cz]+=slowa[cz][a];
   }
  }
  if(b==2)
  {
   if(slowa[cz][a]!='a'&&slowa[cz][a]!='i'&&slowa[cz][a]!='o'&&slowa[cz][a]!='y'
   &&slowa[cz][a]!='u'&&slowa[cz][a]!='u'&&slowa[cz][a]!='e')
   {
    if(slowa[cz][a-1]=='e'||slowa[cz][a-1]=='i')slowa[cz]+=slowa[cz][a];
   }
  }
  if(slowa[cz][a]=='l')
  {
   if(slowa[cz][a-1]=='a'||slowa[cz][a-1]=='i'||slowa[cz][a-1]=='o'||
   slowa[cz][a-1]=='u'||slowa[cz][a-1]=='e')slowa[cz]+='l';
  }
  if(slowa[cz][a]=='e')
  {
   if(slowa[cz][a-1]=='i'){slowa[cz]=slowa[cz].SubString(0, a-2); slowa[cz]+='y';}
   if(slowa[cz]!="age" && slowa[cz]!="dye" && slowa[cz]!="agree"
   && slowa[cz]!="see" && slowa[cz]!="be")slowa[cz]=slowa[cz].SubString(0, a-1);
  }
  slowa[cz]+="ing";
 }
 if(Czas2==3) // perfect continous
 {
  wynik+="been ";
 }
 wynik+=slowa[cz]+' ';
 //dopisanie reszty zdania
 for(unsigned j=cz+1; j<i; j++)
 {
  wynik+=slowa[j]+' ';
 }
 a=wynik.Length();
 wynik=wynik.SubString(0, a-1);
 if(!pytanie){wynik+='.';}else wynik+='?';
 result->Caption=wynik;
}
}
//---------------------------------------------------------------------------
void drugaforma()
{
 while(true)
 {
 if(slowa[cz]=="arise"){slowa[cz]="arose";break;}
 if(slowa[cz]=="awake"){slowa[cz]="awoke";break;}
 if(slowa[cz]=="am"||slowa[cz]=="is"){slowa[cz]="was";break;}
 if(slowa[cz]=="are"){slowa[cz]="were";break;}
 if(slowa[cz]=="bear"){slowa[cz]="bore";break;}
 if(slowa[cz]=="beat"||slowa[cz]=="bet"||slowa[cz]=="burst"
 ||slowa[cz]=="cast"||slowa[cz]=="cost"||slowa[cz]=="cut"
 ||slowa[cz]=="hit"||slowa[cz]=="hurt"||slowa[cz]=="let"
 ||slowa[cz]=="put"||slowa[cz]=="set"||slowa[cz]=="shed"
 ||slowa[cz]=="shut"||slowa[cz]=="split"||slowa[cz]=="thrust"
 ||slowa[cz]=="read"||slowa[cz]=="fit"||slowa[cz]=="knit"
 ||slowa[cz]=="quit"||slowa[cz]=="spread"){break;}
 if(slowa[cz]=="become"){slowa[cz]="became";break;}
 if(slowa[cz]=="begin"){slowa[cz]="began";break;}
 if(slowa[cz]=="bend"){slowa[cz]="bent";break;}
 if(slowa[cz]=="bind"){slowa[cz]="bound";break;}
 if(slowa[cz]=="bite"){slowa[cz]="bit";break;}
 if(slowa[cz]=="bleed"){slowa[cz]="bled";break;}
 if(slowa[cz]=="blow"){slowa[cz]="blew";break;}
 if(slowa[cz]=="break"){slowa[cz]="broke";break;}
 if(slowa[cz]=="breed"){slowa[cz]="bred";break;}
 if(slowa[cz]=="bring"){slowa[cz]="brought";break;}
 if(slowa[cz]=="build"){slowa[cz]="built";break;}
 if(slowa[cz]=="burn"){slowa[cz]="burnt";break;}
 if(slowa[cz]=="buy"){slowa[cz]="bought";break;}
 if(slowa[cz]=="catch"){slowa[cz]="caught";break;}
 if(slowa[cz]=="choose"){slowa[cz]="chose";break;}
 if(slowa[cz]=="cling"){slowa[cz]="clung";break;}
 if(slowa[cz]=="come"){slowa[cz]="came";break;}
 if(slowa[cz]=="creep"){slowa[cz]="crept";break;}
 if(slowa[cz]=="deal"){slowa[cz]="dealt";break;}
 if(slowa[cz]=="dig"){slowa[cz]="dug";break;}
 if(slowa[cz]=="do"){slowa[cz]="did";break;}
 if(slowa[cz]=="draw"){slowa[cz]="drew";break;}
 if(slowa[cz]=="dream"){slowa[cz]="dreamt";break;}
 if(slowa[cz]=="drink"){slowa[cz]="drank";break;}
 if(slowa[cz]=="drive"){slowa[cz]="drove";break;}
 if(slowa[cz]=="eat"){slowa[cz]="ate";break;}
 if(slowa[cz]=="fall"){slowa[cz]="fell";break;}
 if(slowa[cz]=="feed"){slowa[cz]="fed";break;}
 if(slowa[cz]=="feel"){slowa[cz]="felt";break;}
 if(slowa[cz]=="fight"){slowa[cz]="fought";break;}
 if(slowa[cz]=="find"){slowa[cz]="found";break;}
 if(slowa[cz]=="flee"){slowa[cz]="fled";break;}
 if(slowa[cz]=="fling"){slowa[cz]="flung";break;}
 if(slowa[cz]=="fly"){slowa[cz]="flew";break;}
 if(slowa[cz]=="forbid"){slowa[cz]="forbade";break;}
 if(slowa[cz]=="forged"){slowa[cz]="forgot";break;}
 if(slowa[cz]=="forgive"){slowa[cz]="forgave";break;}
 if(slowa[cz]=="forsake"){slowa[cz]="forsook";break;}
 if(slowa[cz]=="foretell"){slowa[cz]="foretold";break;}
 if(slowa[cz]=="freeze"){slowa[cz]="froze";break;}
 if(slowa[cz]=="get"){slowa[cz]="got";break;}
 if(slowa[cz]=="give"){slowa[cz]="gave";break;}
 if(slowa[cz]=="go"){slowa[cz]="went";break;}
 if(slowa[cz]=="grind"){slowa[cz]="ground";break;}
 if(slowa[cz]=="grow"){slowa[cz]="grew";break;}
 if(slowa[cz]=="hang"){slowa[cz]="hung";break;}
 if(slowa[cz]=="have"||slowa[cz]=="has"){slowa[cz]="had";break;}
 if(slowa[cz]=="hear"){slowa[cz]="heard";break;}
 if(slowa[cz]=="hide"){slowa[cz]="hid";break;}
 if(slowa[cz]=="hold"){slowa[cz]="held";break;}
 if(slowa[cz]=="keep"){slowa[cz]="kept";break;}
 if(slowa[cz]=="kneel"){slowa[cz]="knelt";break;}
 if(slowa[cz]=="know"){slowa[cz]="knew";break;}
 if(slowa[cz]=="lay"){slowa[cz]="laid";break;}
 if(slowa[cz]=="lead"){slowa[cz]="led";break;}
 if(slowa[cz]=="leap"){slowa[cz]="leapt";break;}
 if(slowa[cz]=="learn"){slowa[cz]="learnt";break;}
 if(slowa[cz]=="leave"){slowa[cz]="left";break;}
 if(slowa[cz]=="lend"){slowa[cz]="lent";break;}
 if(slowa[cz]=="lie"){slowa[cz]="lay";break;}
 if(slowa[cz]=="light"){slowa[cz]="lit";break;}
 if(slowa[cz]=="lose"){slowa[cz]="lost";break;}
 if(slowa[cz]=="make"){slowa[cz]="made";break;}
 if(slowa[cz]=="mean"){slowa[cz]="meant";break;}
 if(slowa[cz]=="meet"){slowa[cz]="met";break;}
 if(slowa[cz]=="pay"){slowa[cz]="paid";break;}
 if(slowa[cz]=="prove"){slowa[cz]="proved";break;}
 if(slowa[cz]=="ride"){slowa[cz]="rode";break;}
 if(slowa[cz]=="ring"){slowa[cz]="rang";break;}
 if(slowa[cz]=="rise"){slowa[cz]="rose";break;}
 if(slowa[cz]=="run"){slowa[cz]="ran";break;}
 if(slowa[cz]=="saw"){slowa[cz]="sawed";break;}
 if(slowa[cz]=="say"){slowa[cz]="said";break;}
 if(slowa[cz]=="see"){slowa[cz]="saw";break;}
 if(slowa[cz]=="seek"){slowa[cz]="sought";break;}
 if(slowa[cz]=="sell"){slowa[cz]="sold";break;}
 if(slowa[cz]=="send"){slowa[cz]="sent";break;}
 if(slowa[cz]=="shake"){slowa[cz]="shook";break;}
 if(slowa[cz]=="shine"){slowa[cz]="shone";break;}
 if(slowa[cz]=="shoot"){slowa[cz]="shot";break;}
 if(slowa[cz]=="show"){slowa[cz]="showed";break;}
 if(slowa[cz]=="shrink"){slowa[cz]="shrank";break;}
 if(slowa[cz]=="sing"){slowa[cz]="sang";break;}
 if(slowa[cz]=="sink"){slowa[cz]="sank";break;}
 if(slowa[cz]=="sit"){slowa[cz]="sat";break;}
 if(slowa[cz]=="slay"){slowa[cz]="slew";break;}
 if(slowa[cz]=="sleep"){slowa[cz]="slept";break;}
 if(slowa[cz]=="slide"){slowa[cz]="slid";break;}
 if(slowa[cz]=="sling"){slowa[cz]="slung";break;}
 if(slowa[cz]=="speak"){slowa[cz]="spoke";break;}
 if(slowa[cz]=="spend"){slowa[cz]="spent";break;}
 if(slowa[cz]=="spin"){slowa[cz]="spun";break;}
 if(slowa[cz]=="spring"){slowa[cz]="sprang";break;}
 if(slowa[cz]=="stand"){slowa[cz]="stood";break;}
 if(slowa[cz]=="steal"){slowa[cz]="stole";break;}
 if(slowa[cz]=="stick"){slowa[cz]="stuck";break;}
 if(slowa[cz]=="sting"){slowa[cz]="stung";break;}
 if(slowa[cz]=="stink"){slowa[cz]="stank";break;}
 if(slowa[cz]=="strike"){slowa[cz]="struck";break;}
 if(slowa[cz]=="strive"){slowa[cz]="strove";break;}
 if(slowa[cz]=="swear"){slowa[cz]="swore";break;}
 if(slowa[cz]=="sweep"){slowa[cz]="swept";break;}
 if(slowa[cz]=="swim"){slowa[cz]="swam";break;}
 if(slowa[cz]=="swing"){slowa[cz]="swung";break;}
 if(slowa[cz]=="take"){slowa[cz]="took";break;}
 if(slowa[cz]=="teach"){slowa[cz]="taught";break;}
 if(slowa[cz]=="tear"){slowa[cz]="tore";break;}
 if(slowa[cz]=="tell"){slowa[cz]="told";break;}
 if(slowa[cz]=="think"){slowa[cz]="thought";break;}
 if(slowa[cz]=="throw"){slowa[cz]="threw";break;}
 if(slowa[cz]=="tread"){slowa[cz]="trod";break;}
 if(slowa[cz]=="wake"){slowa[cz]="woke";break;}
 if(slowa[cz]=="wear"){slowa[cz]="wore";break;}
 if(slowa[cz]=="weep"){slowa[cz]="wept";break;}
 if(slowa[cz]=="understand"){slowa[cz]="understood";break;}
 if(slowa[cz]=="win"){slowa[cz]="won";break;}
 if(slowa[cz]=="wind"){slowa[cz]="wound";break;}
 if(slowa[cz]=="wring"){slowa[cz]="wrung";break;}
 if(slowa[cz]=="write"){slowa[cz]="wrote";break;}
 int a;
 a=slowa[cz].Length();
  if(slowa[cz][a]=='e')
  {
   slowa[cz]+='d';
  }else slowa[cz]+="ed";
  break;
 }
}
void trzeciaforma()
{
 while(true)
 {
 if(slowa[cz]=="arise"){slowa[cz]="arisen";break;}
 if(slowa[cz]=="awake"){slowa[cz]="awoken";break;}
 if(slowa[cz]=="am"||slowa[cz]=="is"||slowa[cz]=="are"){slowa[cz]="been";break;}
 if(slowa[cz]=="be"){slowa[cz]="been";break;}
 if(slowa[cz]=="bear"){slowa[cz]="borne";break;}
 if(slowa[cz]=="beat"){slowa[cz]="beaten";break;}
 if(slowa[cz]=="bet"||slowa[cz]=="burst"||slowa[cz]=="cast"
 ||slowa[cz]=="cost"||slowa[cz]=="cut"||slowa[cz]=="hit"
 ||slowa[cz]=="hurt"||slowa[cz]=="let"||slowa[cz]=="put"
 ||slowa[cz]=="set"||slowa[cz]=="shed"||slowa[cz]=="shut"
 ||slowa[cz]=="split"||slowa[cz]=="thrust"||slowa[cz]=="read"
 ||slowa[cz]=="fit"||slowa[cz]=="knit"||slowa[cz]=="quit"
 ||slowa[cz]=="spread"||slowa[cz]=="become"||slowa[cz]=="come"
 ||slowa[cz]=="run"){break;}
 if(slowa[cz]=="begin"){slowa[cz]="begun";break;}
 if(slowa[cz]=="bend"){slowa[cz]="bent";break;}
 if(slowa[cz]=="bind"){slowa[cz]="bound";break;}
 if(slowa[cz]=="bite"){slowa[cz]="bitten";break;}
 if(slowa[cz]=="bleed"){slowa[cz]="bled";break;}
 if(slowa[cz]=="blow"){slowa[cz]="blown";break;}
 if(slowa[cz]=="break"){slowa[cz]="broken";break;}
 if(slowa[cz]=="breed"){slowa[cz]="bred";break;}
 if(slowa[cz]=="bring"){slowa[cz]="brought";break;}
 if(slowa[cz]=="build"){slowa[cz]="built";break;}
 if(slowa[cz]=="burn"){slowa[cz]="burnt";break;}
 if(slowa[cz]=="buy"){slowa[cz]="bought";break;}
 if(slowa[cz]=="catch"){slowa[cz]="caught";break;}
 if(slowa[cz]=="choose"){slowa[cz]="chosen";break;}
 if(slowa[cz]=="cling"){slowa[cz]="clung";break;}
 if(slowa[cz]=="creep"){slowa[cz]="crept";break;}
 if(slowa[cz]=="deal"){slowa[cz]="dealt";break;}
 if(slowa[cz]=="dig"){slowa[cz]="dug";break;}
 if(slowa[cz]=="do"){slowa[cz]="done";break;}
 if(slowa[cz]=="draw"){slowa[cz]="drawn";break;}
 if(slowa[cz]=="dream"){slowa[cz]="dreamt";break;}
 if(slowa[cz]=="drink"){slowa[cz]="drunk";break;}
 if(slowa[cz]=="drive"){slowa[cz]="driven";break;}
 if(slowa[cz]=="eat"){slowa[cz]="eaten";break;}
 if(slowa[cz]=="fall"){slowa[cz]="fallen";break;}
 if(slowa[cz]=="feed"){slowa[cz]="fed";break;}
 if(slowa[cz]=="feel"){slowa[cz]="felt";break;}
 if(slowa[cz]=="fight"){slowa[cz]="fought";break;}
 if(slowa[cz]=="find"){slowa[cz]="found";break;}
 if(slowa[cz]=="flee"){slowa[cz]="fled";break;}
 if(slowa[cz]=="fling"){slowa[cz]="flung";break;}
 if(slowa[cz]=="fly"){slowa[cz]="flown";break;}
 if(slowa[cz]=="forbid"){slowa[cz]="forbidden";break;}
 if(slowa[cz]=="forged"){slowa[cz]="forgotten";break;}
 if(slowa[cz]=="forgive"){slowa[cz]="forgiven";break;}
 if(slowa[cz]=="forsake"){slowa[cz]="forsaken";break;}
 if(slowa[cz]=="foretell"){slowa[cz]="foretold";break;}
 if(slowa[cz]=="freeze"){slowa[cz]="frozen";break;}
 if(slowa[cz]=="get"){slowa[cz]="got";break;}
 if(slowa[cz]=="give"){slowa[cz]="given";break;}
 if(slowa[cz]=="go"){slowa[cz]="gone";break;}
 if(slowa[cz]=="grind"){slowa[cz]="ground";break;}
 if(slowa[cz]=="grow"){slowa[cz]="grown";break;}
 if(slowa[cz]=="hang"){slowa[cz]="hung";break;}
 if(slowa[cz]=="have"||slowa[cz]=="has"){slowa[cz]="had";break;}
 if(slowa[cz]=="hear"){slowa[cz]="heard";break;}
 if(slowa[cz]=="hide"){slowa[cz]="hidden";break;}
 if(slowa[cz]=="hold"){slowa[cz]="held";break;}
 if(slowa[cz]=="keep"){slowa[cz]="kept";break;}
 if(slowa[cz]=="kneel"){slowa[cz]="knelt";break;}
 if(slowa[cz]=="know"){slowa[cz]="known";break;}
 if(slowa[cz]=="lay"){slowa[cz]="laid";break;}
 if(slowa[cz]=="lead"){slowa[cz]="led";break;}
 if(slowa[cz]=="leap"){slowa[cz]="leapt";break;}
 if(slowa[cz]=="learn"){slowa[cz]="learnt";break;}
 if(slowa[cz]=="leave"){slowa[cz]="left";break;}
 if(slowa[cz]=="lend"){slowa[cz]="lent";break;}
 if(slowa[cz]=="lie"){slowa[cz]="lain";break;}
 if(slowa[cz]=="light"){slowa[cz]="lit";break;}
 if(slowa[cz]=="lose"){slowa[cz]="lost";break;}
 if(slowa[cz]=="make"){slowa[cz]="made";break;}
 if(slowa[cz]=="mean"){slowa[cz]="meant";break;}
 if(slowa[cz]=="meet"){slowa[cz]="met";break;}
 if(slowa[cz]=="pay"){slowa[cz]="paid";break;}
 if(slowa[cz]=="prove"){slowa[cz]="proved";break;}
 if(slowa[cz]=="ride"){slowa[cz]="ridden";break;}
 if(slowa[cz]=="ring"){slowa[cz]="rung";break;}
 if(slowa[cz]=="rise"){slowa[cz]="risen";break;}
 if(slowa[cz]=="saw"){slowa[cz]="sawn";break;}
 if(slowa[cz]=="say"){slowa[cz]="said";break;}
 if(slowa[cz]=="see"){slowa[cz]="seen";break;}
 if(slowa[cz]=="seek"){slowa[cz]="sought";break;}
 if(slowa[cz]=="sell"){slowa[cz]="sold";break;}
 if(slowa[cz]=="send"){slowa[cz]="sent";break;}
 if(slowa[cz]=="shake"){slowa[cz]="shaken";break;}
 if(slowa[cz]=="shine"){slowa[cz]="shone";break;}
 if(slowa[cz]=="shoot"){slowa[cz]="shot";break;}
 if(slowa[cz]=="show"){slowa[cz]="shown";break;}
 if(slowa[cz]=="shrink"){slowa[cz]="shrunk";break;}
 if(slowa[cz]=="sing"){slowa[cz]="sung";break;}
 if(slowa[cz]=="sink"){slowa[cz]="sunk";break;}
 if(slowa[cz]=="sit"){slowa[cz]="sat";break;}
 if(slowa[cz]=="slay"){slowa[cz]="slain";break;}
 if(slowa[cz]=="sleep"){slowa[cz]="slept";break;}
 if(slowa[cz]=="slide"){slowa[cz]="slid";break;}
 if(slowa[cz]=="sling"){slowa[cz]="slung";break;}
 if(slowa[cz]=="speak"){slowa[cz]="spoken";break;}
 if(slowa[cz]=="spend"){slowa[cz]="spent";break;}
 if(slowa[cz]=="spin"){slowa[cz]="spun";break;}
 if(slowa[cz]=="spring"){slowa[cz]="sprung";break;}
 if(slowa[cz]=="stand"){slowa[cz]="stood";break;}
 if(slowa[cz]=="steal"){slowa[cz]="stolen";break;}
 if(slowa[cz]=="stick"){slowa[cz]="stuck";break;}
 if(slowa[cz]=="sting"){slowa[cz]="stung";break;}
 if(slowa[cz]=="stink"){slowa[cz]="stunk";break;}
 if(slowa[cz]=="strike"){slowa[cz]="struck";break;}
 if(slowa[cz]=="strive"){slowa[cz]="striven";break;}
 if(slowa[cz]=="swear"){slowa[cz]="sworn";break;}
 if(slowa[cz]=="sweep"){slowa[cz]="swept";break;}
 if(slowa[cz]=="swim"){slowa[cz]="swum";break;}
 if(slowa[cz]=="swing"){slowa[cz]="swung";break;}
 if(slowa[cz]=="take"){slowa[cz]="taken";break;}
 if(slowa[cz]=="teach"){slowa[cz]="taught";break;}
 if(slowa[cz]=="tear"){slowa[cz]="torn";break;}
 if(slowa[cz]=="tell"){slowa[cz]="told";break;}
 if(slowa[cz]=="think"){slowa[cz]="thought";break;}
 if(slowa[cz]=="throw"){slowa[cz]="thrown";break;}
 if(slowa[cz]=="tread"){slowa[cz]="trodden";break;}
 if(slowa[cz]=="wake"){slowa[cz]="woken";break;}
 if(slowa[cz]=="wear"){slowa[cz]="worn";break;}
 if(slowa[cz]=="weep"){slowa[cz]="wept";break;}
 if(slowa[cz]=="understand"){slowa[cz]="understood";break;}
 if(slowa[cz]=="win"){slowa[cz]="won";break;}
 if(slowa[cz]=="wind"){slowa[cz]="wound";break;}
 if(slowa[cz]=="wring"){slowa[cz]="wrung";break;}
 if(slowa[cz]=="write"){slowa[cz]="written";break;}
 int a;
 a=slowa[cz].Length();
 if(slowa[cz][a]=='e')
  {
   slowa[cz]+='d';
  }else slowa[cz]+="ed";
  break;
 }
}
void __fastcall TForm1::InThePastClick(TObject *Sender)
{
 Czas2=4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PerfectPClick(TObject *Sender)
{
 Czas2=5;
}
//---------------------------------------------------------------------------

