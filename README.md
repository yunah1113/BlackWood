# 블랙우드 농장: 엇갈린 사랑

> 황금 조각상을 찾아 들어간 광산에서, 두 사람의 엇갈린 사랑을 목격하고 탈출하는 1인칭 내러티브 어드벤처.

▶︎ [상세 보고서 보기](https://docs.google.com/document/d/1Iyc93ywdvLiulU9XX5HDxOi9p8R7U3KNMJsuRj0eHjI/edit?usp=sharing)

[게임플레이 영상 보기](https://drive.google.com/file/d/1DII4dYx2whtO2ac66Ur2cfzu5kFN27w9/view?usp=sharing)

---

## 한 줄 요약

장르: 1인칭 내러티브 어드벤처 / 제작 기간: 2주 / 사용 기술: Unreal Engine 5, C++, Blueprint / 1인 개발

---

## 핵심 기능 3가지

1. **수집 시스템** — C++ GameMode에서 맵 내 액터를 자동 순회해 돌 39개·쪽지 3개를 집계. 아이템 수가 바뀌어도 코드 수정 없이 자동 반영
2. **순차 대사 시스템** — Blueprint에서 Set Text → Delay(4~6초) 체인으로 13개 대사를 타이머 없이 순서대로 표시. 마지막 대사 완료 후 엔딩 시퀀스로 자연스럽게 연결
3. **NPC 트리거 & 엔딩 시퀀스** — Box Collision 기반 NPC 접근 감지 → 대사 시작 → Camera Fade(2초) → Quit Game까지 하나의 Blueprint 흐름으로 연결

![게임플레이: 대사 시스템](https://github.com/user-attachments/assets/ac9fcd49-73d9-431e-82de-c968f60f52f6)

---

## 내가 직접 만든 부분

- 기획, 스토리, 등장인물, 대사, 게임 흐름 설계 (100%)
- C++ GameMode 작성 — 수집 자동 카운팅, 진행도 텍스트, 쪽지 팝업 함수
- Blueprint 구현 — 대사 시스템, 위젯 연동, 엔딩 시퀀스
- 레벨 디자인 — 광산 맵 제작, 돌·쪽지·NPC 배치
- UI 스타일링 — 팔레트 및 텍스트 블록 스타일 적용
- 외부 에셋 (Fab 마켓플레이스): 캐릭터 Skeletal Mesh 3종, 황금 조각상·바·장식 3D 모델, 쪽지·돌·바닥·벽 메시

---

## 기술적 도전

**문제**: 대사 시스템 구현 중 Set Text 노드 13개 전부 ERROR 표시되며 컴파일 실패

**원인**: Actor Blueprint에서 self를 Rich Text Block Target으로 연결 시 타입 불일치. 위젯 내부 SubText 컴포넌트를 직접 참조해야 함을 확인

**해결**: DT_TextStyle Data Table 생성 후 W Subtitle에 연동 → Return Value를 NewVar로 Promote to Variable → Get SubText로 13개 Set Text Target 전부 연결

**배움**: 단순히 try-and-error로 고치지 않고 Output Log와 show collision으로 변수 흐름을 추적해 근본 원인을 찾는 습관을 익혔습니다. 막히는 구현이 생겼을 때 구조 자체를 바꾸는 방향으로 전환하는 판단도 경험했습니다. (투명벽 → NPC Overlap 방식 전환)

→ [상세 트러블슈팅은 프로젝트 보고서 참조](https://docs.google.com/document/d/1Iyc93ywdvLiulU9XX5HDxOi9p8R7U3KNMJsuRj0eHjI/edit?usp=sharing)

---

## 기술 스택

- Unreal Engine 5, C++, Blueprint, Rider
- Fab 마켓플레이스 무료 에셋 활용

---

## 빌드 방법

1. 이 저장소를 클론합니다
2. `.uproject` 파일을 Unreal Engine 5로 엽니다
3. 에디터에서 플레이 버튼을 눌러 실행합니다

---

## 보고서·문서

- [프로젝트 진행 보고서](https://docs.google.com/document/d/1Iyc93ywdvLiulU9XX5HDxOi9p8R7U3KNMJsuRj0eHjI/edit?usp=sharing) — 핵심 기능 3가지, 트러블슈팅 3가지, 회고 전체 수록
